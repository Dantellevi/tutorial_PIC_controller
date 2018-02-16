/*
 * File:   main.c
 * Author: Dante_L_Levi
 *
 * Created on 12 февраля 2018 г., 20:30
 */


#include <xc.h>
#include "Main.h"
#include <stdio.h>
#include <stdlib.h>

unsigned char RTC_ConvertFromBinDec(unsigned char c)
{
  unsigned char ch = ((c/10)<<4)|(c%10);
  return ch;

}


unsigned char RTC_ConvertFromDec(unsigned char c)
{
  unsigned char ch = ((c>>4)*10+(0b00001111&c));
  return ch;
}




void main(void) {
    unsigned char sec;
    unsigned char min;
    unsigned char hour;
     char buffer[40];
    //nRBPU = 0;                    //Enable PORTB internal pull up resistor
    //TRISC6=1;
   // PORTCbits.RC6=0;
  char status=USART_Init(9600);
  //TRISB = 0xFF;                 //PORTB as input
  //TRISD = 0x00;                 //PORTD as output
  //PORTD = 0x00;                 //All LEDs OFF
  I2C_Master_Init(100000);      //Initialize I2C Master with 100KHz clock
  RTC_Init();
  rtc_t rtc;
  rtc.hour = 0x10; //  10:40:20 am
    rtc.min =  0x40;
    rtc.sec =  0x00;

    //rtc.date = 0x01; //1st Jan 2016
   // rtc.month = 0x01;
   // rtc.year = 0x16;
    //rtc.weekDay = 5; // Friday: 5th day of week considering monday as first day.
  Usart_PrintString("Hello\r\n");
   RTC_SetDateTime(&rtc);
    while(1)
    {
        __delay_ms(300);
        RTC_GetDateTime(&rtc);
        __delay_ms(300);
        sec=(char)rtc.sec;
        min=(char)rtc.min;
        hour=(char)rtc.hour;
        
        sprintf(buffer,"Time= %u : %u :%u ",RTC_ConvertFromDec(hour),RTC_ConvertFromDec(min),RTC_ConvertFromDec(sec));
        Usart_PrintString(buffer);
        Transmit_char(0x0D);
        Transmit_char(0x0A);
        __delay_ms(500);
        //Start condition
    
        //I2C_Master_Start();
        //I2C_Write_Byte(0x3F);
       // __delay_ms(1000);
        //I2C_Master_Stop(); 
    
             //Stop condition
        
        
        
    
    }
    
}
