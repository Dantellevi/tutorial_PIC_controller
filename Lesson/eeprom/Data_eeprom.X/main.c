
#define _XTAL_FREQ 4000000
#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


uint8_t readEEPROM(uint8_t address)
{
    EEADR=address;//адрес для чтения байта
    EEPGD=0;//выборо еепром памяти
    RD=1;    //указываем что будем читать
    return EEDATA;
}

void WriteEEPROM(uint8_t address,uint8_t dataes)
{
    unsigned char INTCON_SAVE;//переменная для хранения значения регистра INCON
    EEADR = address; //Address to write
    EEDATA = dataes; //Data to write
    EEPGD=0;//Selecting EEPROM Data Memory
    WREN=1; //Enable writing of EEPROM
    INTCON_SAVE=INTCON;//Backup INCON interupt register
    INTCON=0; //Diables the interrupt
    
    EECON2=0x55; //Required sequence for write to internal EEPROM
    EECON2=0xAA; //Required sequence for write to internal EEPROM
    WR = 1; //Initialise write cycle
    INTCON = INTCON_SAVE;//Enables Interrupt
    WREN = 0; //To disable write
    
    while(EEIF == 0)//Checking for complition of write operation
  {
    asm("nop"); //do nothing
  }
  EEIF = 0; //Clearing EEIF bit
}



void main(void) {
    
    unsigned int a, i;
    TRISC = 0;
 
    

    
    while(1)
    {
        for(i=0,a=1;i<8;i++)
        {
            WriteEEPROM(i, a);
             a = a<<1;
        }
         for(i=0;i<8;i++)
        {
            PORTC = readEEPROM(i);
            __delay_ms(1000);
        }
    }
}
