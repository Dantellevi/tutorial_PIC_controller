#include "EEPROM.h"

/*
 ===============Функция записи байта по определенному адресу=======
 */
void EEPROM_WriteByte(uint8_t addr,uint8_t dt)
{
    
    uint8_t status;
    while(WR);
    EEADR=addr; //записываем адрес
    EEDATA=dt;  //записываем данные
    
    WREN=1;
    
    status=GIE;
    
    GIE=0;
    
    EECON2=0x55;
    EECON2=0xAA;
    
    WR=1;
    GIE=status;
    WREN=0;
    
}


/*
 =====================Функция чтения байтаа из определенного адреса========
 */
uint8_t EEPROM_ReadByte(uint8_t addr)
{
    while(RD||WR);
    
    EEADR=addr;
    RD=1;
    
    return EEDATA;
}


/*
 =========Функция записи целочисленного двух байтовой величины============
 */
void EEPROM_WriteWord(uint8_t addr, uint16_t ucData)
{
    EEPROM_WriteByte(addr,(uint8_t)ucData);
    uint8_t dt=ucData>>8;
    EEPROM_WriteByte(addr+1,dt);
}

/*
 ==============================Функция чтения двух байт из адресов===============
 */
uint16_t EEPROM_ReadWord(uint8_t addr)
{
    uint16_t dt=EEPROM_ReadByte(addr+1)*256;
    dt+=EEPROM_ReadByte(addr);
    return dt;
    
}





/*
 ===========================Функция записи 4 байта===========================
 */
void EEPROM_WriteDWord(uint16_t addr,unsigned long ucData)
{
    EEPROM_WriteWord(addr,(uint16_t) ucData);
    uint16_t dt=ucData>>16;
    EEPROM_WriteWord(addr+2,dt);
    
}


/*
 ==================Функция чтения 4 байтной величины==================
 */
uint32_t EEPROM_ReadDWord(uint8_t addr)
{
    uint32_t dt=EEPROM_ReadWord(addr+2)*65535;
    dt+=EEPROM_ReadWord(addr);
    return dt;
    
}

/*
 ===========Записываем строку в EEPROM===========================
 */
void EEPROM_WriteString(uint8_t addr,char *str1)
{
    uint8_t n=0;
    for(n=0;str1[n]!='\n';n++)
    {
        EEPROM_WriteByte(addr+n,str1[n]);
    }
}

/*
 ===========================Читаем строку из адреса===================
 */
void EEPROM_ReadString(uint8_t addr,char *str1,uint8_t sz)
{
    unsigned char  i;
    for(i=0;i<sz;i++)
    {
        str1[i]=EEPROM_ReadByte(addr+i);
    }
}










