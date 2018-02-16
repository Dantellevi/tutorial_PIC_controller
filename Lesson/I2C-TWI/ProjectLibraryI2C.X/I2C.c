#include "I2C.h"
short z;

/***************************************************************************************************
                          Local Function declaration
***************************************************************************************************/


static void i2c_Ack();
static void i2c_NoAck();
/**************************************************************************************************/



/*
 * ===========================Функция инициализации=====
 *      Принимаемые параметры:
 *              c-скорость передачи/приема данных
 */

void I2C_Master_Init(unsigned long int c)
{
  SSPCON = 0x28;            //SSP Module as Master
  SSPCON2 = 0;
  SSPADD = (_XTAL_FREQ/(4*c))-1; //Setting Clock Speed
  SSPSTAT |= 0x80;  /* Slew rate disabled */
  TRISC3=1;
  TRISC4=1;
}   

//=======================================================


/*
 * ===========================Функция ожидание передачи данных=========
 */
void I2C_Master_Wait(void)
{
  while ( (SEN == 1) || (RSEN == 1) || (PEN == 1) || (RCEN == 1) || (R_W == 1) );
    /* wait till I2C module completes previous operation and becomes idle */
}
//=====================================================================


/*
 ===========================Функция Старта работы I2C===============
 */
void I2C_Master_Start(void)
{
    SEN=1;      //бит инициализации запуска интерфейса
    while(SEN == 1);      /* automatically cleared by hardware once start condition is completed */
}

//==================================================================


/*
 ============================Функция Перезапуска интерфейса==========
 */
void I2C_Master_RepeatedStart(void)
{
    RSEN = 1;        /* Repeated start enabled */
	while(RSEN);     /* wait for condition to finish */
}

//====================================================================


/*
 ==============================Функция остоновки интерфейса==========
 */
void I2C_Master_Stop(void)
{
   
    PEN=1;      //бит , управляющий остановкой приема/передачей данных
    while(PEN == 1);      /* PEN automatically cleared by hardware once stop condition is finished*/
    
}


/*
 =====================Функция записи данных в буффер===========
 *      Принимаемые параметры:
 *              data- данные для передачи
 */
void I2C_Write_Byte(unsigned char data)
{
    SSPBUF = data;  /* Copy the data to be transmitted into SSPBUF */
    while(BF==1);             /* wait till the data is transmitted */
    I2C_Master_Wait();       /* wait till current operation is complete*/
}
//==============================================================

void I2C_SendByteByADDR(unsigned char c,unsigned char addr)
{
    I2C_Master_Start();
    I2C_Write_Byte(addr);
    I2C_Write_Byte(c);
    I2C_Master_Stop();
}

/*
 ============================Функция чтения байта==============
 
 
 */
unsigned char I2C_Master_Read(unsigned char a)
{
  char  v_i2cData_u8=0x00;

	RCEN = 1;                   /* Enable data reception */
	while(BF==0);               /* wait for data to be received */
	v_i2cData_u8 = SSPBUF;    /* copy the received data */
	I2C_Master_Wait();          /* wait till current operation is complete*/
	      
	if(a==1)     /*Send the Ack/NoAck depending on the user option*/
	{
		i2c_Ack();
	}
	else
	{
		i2c_NoAck();
	}

	return v_i2cData_u8;       /* Finally return the received Byte */
  
}


/***************************************************************************************************
                         static void i2c_Ack()
 ***************************************************************************************************
 * I/P Arguments: none.
 * Return value  : none

 * description  :This function is used to generate a the Positive ACK
                 pulse on SDA after receiving a byte.
***************************************************************************************************/
static void i2c_Ack()
{
	ACKDT = 0;            /* Acknowledge data bit, 0 = ACK */
	ACKEN = 1;            /* Ack data enabled */
	while(ACKEN == 1);    /* wait for ack data to send on bus */
}





/***************************************************************************************************
                        static void i2c_NoAck()
 ***************************************************************************************************
 * I/P Arguments: none.
 * Return value  : none

 * description  :This function is used to generate a the Negative/NO ACK
                 pulse on SDA after receiving all bytes.
***************************************************************************************************/
static void i2c_NoAck()
{
	ACKDT = 1;            /* Acknowledge data bit, 1 = NAK/NoAK */
	ACKEN = 1;            /* Ack data enabled */
	while(ACKEN == 1);    /* wait for ack data to send on bus */
}


