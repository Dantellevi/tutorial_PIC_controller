/*
 * File:   main.c
 * Author: Dante_L_Levi
 *
 * Created on 14 января 2018 г., 17:30
 */

#include <xc.h>
#include "lcd.h"
#define _XTAL_FREQ 4000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (Power-up Timer is enabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)



void Port_Init(void)
{
    TRISA=0x00;
    PORTA=0x00;
    
    TRISB=0x00;
    PORTB=0x00;
    
    
}


void main(void) {
    
    Port_Init();
    LCDinit();
    LCDstringXY("Hello World!!",0,0);
    while(1)
    {
        
    }
}
