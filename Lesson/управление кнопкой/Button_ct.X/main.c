/*
 * File:   main.c
 * Author: Dante_L_Levi
 *
 * Created on 17 декабря 2017 г., 11:30
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


#define delay 450
#define P0  0
#define P1  1
#define P2  2
#define P3  3
#define P4  4
#define P5  5
#define P6  6
#define P7  7


void Port_Init(void)
{
    TRISA&=~((1<<P0)|(1<<P1));
    TRISA|=(1<<P2);
    
    TRISB=0x00;
    PORTAbits.RA0=0;
    PORTAbits.RA1=0;
    
    
    PORTBbits.RB0=0;
    PORTBbits.RB1=0;
    PORTBbits.RB2=0;
    PORTBbits.RB3=0;
    PORTBbits.RB4=0;
    PORTBbits.RB5=0;
    PORTBbits.RB6=0;
    PORTBbits.RB7=0;
    
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
    
    Port_Init();
    while(1)
    {
        if(check_Button()==1)
        {
            PORTBbits.RB0=1;
            PORTAbits.RA1=0;
            __delay_ms(delay);
        
       
            PORTBbits.RB1=1;
            PORTBbits.RB0=0;
            __delay_ms(delay);
        
         
         
            PORTBbits.RB2=1;
            PORTBbits.RB1=0;
            __delay_ms(delay);
        
            PORTBbits.RB3=1;
            PORTBbits.RB2=0;
            __delay_ms(delay);
        
         
         
            PORTBbits.RB4=1;
            PORTBbits.RB3=0;
            __delay_ms(delay);
        
        
            PORTBbits.RB5=1;
            PORTBbits.RB4=0;
            __delay_ms(delay);
        
        
         
            PORTBbits.RB6=1;
            PORTBbits.RB5=0;
            __delay_ms(delay);
        
        
            PORTBbits.RB7=1;
            PORTBbits.RB6=0;
            __delay_ms(delay);
        
        
         
         
             PORTAbits.RA0=1;
             PORTBbits.RB7=0;
            __delay_ms(delay);
        
        
            PORTAbits.RA1=1;
            PORTAbits.RA0=0;
            __delay_ms(delay);
        }
        else
        {
            PORTAbits.RA0=0;
            PORTAbits.RA1=0;
    
    
            PORTBbits.RB0=0;
            PORTBbits.RB1=0;
            PORTBbits.RB2=0;
            PORTBbits.RB3=0;
            PORTBbits.RB4=0;
            PORTBbits.RB5=0;
            PORTBbits.RB6=0;
            PORTBbits.RB7=0;
        }
        
    }
}
