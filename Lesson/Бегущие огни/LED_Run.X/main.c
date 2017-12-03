/*
 * File:   main.c
 * Author: Dante_L_Levi
 *
 * Created on 3 декабря 2017 г., 19:14
 */


#include <xc.h>

#define _XTAL_FREQ 4000000
#define delay 300
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (Power-up Timer is enabled)
#pragma config CP = ON          // Code Protection bit (All program memory is code protected)

void main(void) {
    
    TRISB=0x00;     //конфигурируем регистр порта В на выход
    PORTB=0x00;     //устанавливаем биты порта в 0
    
    
    TRISA&=~((1<<0)|(1<<1));    //устанавливаем биты регистра А(0,1) на выход
    PORTAbits.RA0=0;            //устанавливаем на PINA0 и PINA1 0 
    PORTAbits.RA1=0;            //устанавливаем на PINA0 и PINA1 0
    
    while(1)
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
}
