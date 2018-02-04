


#include <xc.h>

#define _XTAL_FREQ 8000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (Power-up Timer is enabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)


#define TMR2PRESCALE 4  //?????????? ????????????
long int freq=1000;         //??????? ????????????? ???



/*
 ============================??????? ?????????????=====================
 */

void PWM_Init(void)
{
    PR2 = (_XTAL_FREQ/(freq*4*TMR2PRESCALE)) - 1; //Setting the PR2 formulae using Datasheet
    //PWM work in 5KHZ
    //ON PWM Mode
    CCP1M3=1;
    CCP1M2=1;
    //----------------------------------------------
    //-----------------TIMER Config-----------
    //ON prescale  4
    T2CKPS0 = 1;
    T2CKPS1 = 0;
    
    //------------------------------------------------------
    TRISC2=0;   //Config PINC pin2 output
}

void PWM_Duty (unsigned int duty)
{
if (duty<1023)
{
duty=((float)duty /1023) * (_XTAL_FREQ/(freq*TMR2PRESCALE)); // ?? ?????????? // duty = (((?oat) duty / 1023) * (1 / PWM_freq)) / ((1 / _XTAL_FREQ) *
//TMR2PRESCALE);
CCP1X = duty & 1; // save 1 bit
CCP1Y = duty & 2; // save 0 bit
CCPR1L = duty >> 2; // save other 8 bits
}
}


void main(void) 
{
    TRISC=0x00;
    PORTC=0x00;
    PWM_Init();
    PWM_Duty(500);
    while(1)
    {
        
    }
    
}
