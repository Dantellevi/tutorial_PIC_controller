/*
 * File:   main.c
 * Author: Dante_L_Levi
 *
 * Created on 24 декабр€ 2017 г., 20:23
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



//=======================ƒефайны дл€ таймера счетчика======================
#define PS2 2
#define PS1 1
#define PS0 0

#define GIE 7
#define T0IE 5

//-----------------------------------------------------------------

unsigned int TIM0_count=0;


//------------------обработчик прерывани€ по переполнению--------------------
void interrupt timer0()
{
    //таймер начинает счет и в зависимости от значени€ вывод различные показани€ на порт
    switch(TIM0_count%10)

  {

  case 0:

  PORTAbits.RA1 = 0;

  PORTBbits.RB0 = 1;

  break;

  case 1:

    PORTBbits.RB0 = 0;

    PORTBbits.RB1 = 1;

    break;

  case 2:

    PORTBbits.RB1 = 0;

    PORTBbits.RB2 = 1;

    break;

  case 3:

    PORTBbits.RB2 = 0;

    PORTBbits.RB3 = 1;

    break;

  case 4:

    PORTBbits.RB3 = 0;

    PORTBbits.RB4 = 1;

    break;

  case 5:

    PORTBbits.RB4 = 0;

    PORTBbits.RB5 = 1;

    break;

  case 6:

    PORTBbits.RB5 = 0;

    PORTBbits.RB6 = 1;

    break;

  case 7:

    PORTBbits.RB6 = 0;

    PORTBbits.RB7 = 1;

    break;

  case 8:

    PORTBbits.RB7 = 0;

    PORTAbits.RA0 = 1;

    break;

  case 9:

    PORTAbits.RA0 = 0;

    PORTAbits.RA1 = 1;

    break;

  }
    
TIM0_count++;           //инкреминтируем глобальную переменную таймера
if(TIM0_count>3999)         //сбрасываем переменную в ноль
{
  TIM0_count=0;
}
//T0IF (TMR0 Overflow Interrupt Flag) Ч флаг прерывани€ по переполнению таймера 0:
//0 Ч внешнего прерывани€ нет, 1 Ч произошло переполнение счЄтчика таймера 0 (сбрасываетс€ программно).
T0IF=0;

    
}
//----------------------------------------------------------------------------


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


void timer_init(void)
{
    //частота будет не 4ћ√ц а в четыри раза меньше в PIC используютс€ машинные циклы
    
    OPTION_REG=(1<<PS2)|(1<<PS1)|(1<<PS0);      //включаем предделитель на 256 (111)-1000000/256=3.9к√ц
    //Ќо так как таймер будет считать от 0 до 255, то мы ещЄ раз делим на 256 и получаем приблизительно 15,3 √ц
    //--------------------------------------------------------------------------------------------------
    
    //GIE (Global Interrupt Enable) Ч 
    //разрешение глобальных прерываний: 
    //0 Ч все прерывани€ запрещены, 
    //1 Ч все немаскированные прерывани€ разрешены.
    //----------------------------------------------------------
    //T0IE (TMR0 Overflow Interrupt Enable) Ч 
    //разрешение прерывани€ по переполнению таймера 0: 
    //0 Ч прерывание запрещено, 1 Ч прерывание разрешено.
    
    INTCON=(1<<GIE)|(1<<T0IE);
    //-------------------------------------------------------------------------------------------------
    TMR0=0;     //запускаем таймер при этом пропускаютс€ два машинных цикла
    
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
    timer_init();
    
    
    while(1)
    {
        
    }
}
