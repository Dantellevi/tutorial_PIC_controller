/*
 * File:   main.c
 * Author: Dante_L_Levi
 *
 * Created on 1 ÿםגאנÿ 2018 ד., 21:18
 */


#include <xc.h>

#define _XTAL_FREQ 4000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (Power-up Timer is enabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)


char digit=0;

#define delay 450
#define P0  0
#define P1  1
#define P2  2
#define P3  3
#define P4  4
#define P5  5
#define P6  6
#define P7  7


void Port_init(void)
{
    TRISB=0x00;
    PORTB=0x00;
        TRISA|=(1<<P2);
}





void OutputChar(char digit)
{
    switch(digit)
    {
        case 0:
        {
            PORTB=0x3F;
            break;
        }
        case 1:
        {
            PORTB=0x06;
            break;
        }
        case 2:
        {
            PORTB=0x5B;
            break;
        }
        case 3:
        {
            PORTB=0x4F;
            break;
        }
        case 4:
        {
            PORTB=0x66;
            break;
        }
        case 5:
        {
            PORTB=0x6D;
            break;
        }
        case 6:
        {
            PORTB=0x7D;
            break;
        }
        case 7:
        {
            PORTB=0x07;
            break;
        }
        case 8:
        {
            PORTB=0x7F;
            break;
        }
        case 9:
        {
            PORTB=0x6F;
            break;
        }
        case 10:
        {
            PORTB=0x80;
            break;
        }
    }
}

unsigned char check_Button(void)
{
    unsigned char result=0;
    unsigned int butcount=0;
    
    while(!RA2)
    {
        if(butcount<10000)
        {
            butcount++;
        }
        else
        {
            result=1;
            break;
        }
    }
    
    return result;
}

void main(void) {
    
    Port_init();
    
    while(1)
    {
        if(check_Button()==1)
        {
            digit++;
            __delay_ms(100);
        }
        
     OutputChar(digit); 
     
     if(digit>10)
     {
         digit=0;
     }
    }
   
}
