#include "Main.h"



void main(void)
{
    char str1[21];
    unsigned long i=0,j=0,dtt=0;
    lcd_init(0);
    //---------Запись---------
    for(i=0;i<40;i++)
    {
        EEPROM_WriteByte(i,0x40+i);
    }
    
    //----------Чтение------------
    for(j=0;j<4;j++)
    {
       for(i=0;i<10;i++)
        {
            dtt=EEPROM_ReadByte(j*10+i);
            sprintf(str1,"%02x",dtt);
            lcd_printStringXY(i*2,j,str1);
            
        } 
       
    }
    
    
    while(1)
    {
        
    }
}


