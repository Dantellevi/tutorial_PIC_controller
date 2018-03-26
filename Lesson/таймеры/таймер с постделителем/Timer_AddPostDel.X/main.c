#include "Main.h"
#include <xc.h>
uint8_t R1=0;
uint8_t R2=0;
uint8_t R3=0;
uint8_t R4=0;

uint16_t TIM1_Count=0;
uint8_t n_count=0;
unsigned char ncnt=0;
void TIM2_CallBack(void);

void interrupt isr(void)
{
    if(TMR0IE&&TMR0IF)  //если произошло прерывания таймера 0 и флаг переполнения установлен в таймере 0
  {
    TIM2_CallBack();
    T0IF=0;
  }
  else if(TMR2IE&&TMR2IF)   //если произошло прерывания таймера 2 и флаг переполнения установлен в таймере 2
  {
    TMR2IF=0;
    ncnt++;
    if(ncnt>25)     //программный делитель 25Гц/25 прибавление происходит раз в 25 Гц
    {
      ncnt=0;
      TIM1_Count++;
      if(TIM1_Count>9999) TIM1_Count=0;
    }
  }
}


void Port_Init(void)
{
    TRISA0=0;
    TRISA1=0;
    TRISA2=0;
    TRISA3=0;
    
   PORTAbits.RA0=0;
   PORTAbits.RA1=0;
   PORTAbits.RA2=0;
   PORTAbits.RA3=0;
   
   TRISD=0x00;
   PORTD=0x00;
  
}



//-----------------------------Функция вывода разряда------------------------------------
void ledprint(unsigned int number)
{

	 R1 = number%10;		//4
	 R2 = number%100/10;	//3
	 R3 = number%1000/100;	//2
	 R4 = number/1000;		//1
 }

//-----------------------------------------------------------------------------------

//----------------------------Функция вывода кода цифры------------------------------

void segchar (unsigned char seg)
{
	switch(seg)
	{
		case 1: PORTD = 0b11111001; break;
		case 2: PORTD = 0b10100100; break;
		case 3: PORTD = 0b10110000; break;
		case 4: PORTD = 0b10011001; break;
		case 5: PORTD = 0b10010010; break;
		case 6: PORTD = 0b10000010; break;
		case 7: PORTD = 0b11111000; break;
		case 8: PORTD = 0b10000000; break;
		case 9: PORTD = 0b10010000; break;
		case 0: PORTD = 0b11000000; break;
	}
}



/*
 ===========================Функция обработки прерывания================
 */
void TIM2_CallBack(void)
{
    ledprint(TIM1_Count);
    
    if(n_count==0)
    {
        PORTAbits.RA3=0;
        segchar(R1);
        PORTAbits.RA0=1;
    }
    if(n_count==1)
    {
         PORTAbits.RA0=0;
         segchar(R2);
         PORTAbits.RA1=1;
    }
    if(n_count==2)
    {
         PORTAbits.RA1=0;
         segchar(R3);
         PORTAbits.RA2=1;
    }
    if(n_count==3)
    {
         PORTAbits.RA2=0;
         segchar(R4);
         PORTAbits.RA3=1;
    }
     n_count++;
  if (n_count>3) n_count=0;
}


void Timer2_Init(void)
{
    
    //=========Пост делитель равен 10====
    TOUTPS0=1;
    TOUTPS1=0;
    TOUTPS2=0;
    TOUTPS3=1;
    //=====================================
    
    //==============Предделитель равен 16======
    T2CKPS1=1;
    T2CKPS0=1;
    //=========================================
    
    //30Гц=1000000/10/16/x
    //x=1000000/10/16/30Hz
    //Pr2=x-1
    PR2=0xF9;     //25Гц
    TMR2IE=1;       //вкл. прерывания
    TMR2ON=1;       //вкл. таймер 2
    
    
}


void main(void) {
    
    Port_Init();
    T0IE=1;
    GIE=1;
    PEIE=1;
    OPTION_REG=0b00000010; //Prescaler 8
    Timer2_Init();
    TMR0=0;
    while(1)
    {
        
    }
}
