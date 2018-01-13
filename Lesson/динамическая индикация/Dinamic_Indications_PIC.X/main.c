/*
 * File:   main.c
 * Author: Dante_L_Levi
 *
 * Created on 24 декабря 2017 г., 20:23
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



//=======================Дефайны для таймера счетчика======================
#define PS2 2
#define PS1 1
#define PS0 0

#define GIE 7
#define T0IE 5


//--------------------------------Переменные разряда-------------------------------------
unsigned char R1;
unsigned char R2;
unsigned char R3;
unsigned char R4;


//-----------------------------Функция вывода разряда------------------------------------
void ledprint(unsigned int number)
{

	 R1 = number%10;		//4
	 R2 = number%100/10;	//3
	 R3 = number%1000/100;	//2
	 R4 = number/1000;		//1
 }

//-----------------------------------------------------------------------------------

//----------------------------Функция вывода кода цифры------------------------------

void segchar (unsigned char seg)
{
	switch(seg)
	{
		case 1: PORTB = 0b11111001; break;
		case 2: PORTB = 0b10100100; break;
		case 3: PORTB = 0b10110000; break;
		case 4: PORTB = 0b10011001; break;
		case 5: PORTB = 0b10010010; break;
		case 6: PORTB = 0b10000010; break;
		case 7: PORTB = 0b11111000; break;
		case 8: PORTB = 0b10000000; break;
		case 9: PORTB = 0b10010000; break;
		case 0: PORTB = 0b11000000; break;
	}
}

//----------------------------------------------------------------------------------
unsigned char n_count=0;        //счетчик вывода разряда

//------------------обработчик прерывания по переполнению--------------------
void interrupt timer0()
{
   
    if(n_count==0)
    {
        
        PORTAbits.RA0=1;
        PORTAbits.RA1=0;
        PORTAbits.RA2=0;
        PORTAbits.RA3=0;
         
        segchar(R4);
        
    }
    else if(n_count==1)
    {
        
        PORTAbits.RA0=0;
        PORTAbits.RA1=1;
        PORTAbits.RA2=0;
        PORTAbits.RA3=0;
        
        segchar(R3);
    }
    else if(n_count==2)
    {
        PORTAbits.RA0=0;
        PORTAbits.RA1=0;
        PORTAbits.RA2=1;
        PORTAbits.RA3=0;
        segchar(R2);
    }
    else if(n_count==3)
    {
        PORTAbits.RA0=0;
        PORTAbits.RA1=0;
        PORTAbits.RA2=0;
        PORTAbits.RA3=1;
        segchar(R1);
    }
    n_count++;
    if(n_count>3)
    {
        n_count=0;
    }
   
//T0IF (TMR0 Overflow Interrupt Flag) — флаг прерывания по переполнению таймера 0:
//0 — внешнего прерывания нет, 1 — произошло переполнение счётчика таймера 0 (сбрасывается программно).
   // PORTA^=0x01;
    T0IF=0;
    TMR0=216;
    
}
//----------------------------------------------------------------------------

//=====================Инициализация портов ввода/вывода======================
void Port_Init(void)
{
    TRISA=0x00;
    TRISB=0x00;
    
    PORTA=0x00;
    PORTB=0x00;
    
    
}

//===================================Инициализация таймера счетчика(8-бит)======================
void timer_init(void)
{
    //частота будет не 4МГц а в четыри раза меньше в PIC используются машинные циклы
    
    OPTION_REG=(1<<PS2)|(1<<PS1)|(1<<PS0);      //включаем предделитель на 256 (111)-1000000/256=3.9кГц
    //Но так как таймер будет считать от 0 до 255, то мы ещё раз делим на 256 и получаем приблизительно 15,3 Гц
    //--------------------------------------------------------------------------------------------------
    
    //GIE (Global Interrupt Enable) — 
    //разрешение глобальных прерываний: 
    //0 — все прерывания запрещены, 
    //1 — все немаскированные прерывания разрешены.
    //----------------------------------------------------------
    //T0IE (TMR0 Overflow Interrupt Enable) — 
    //разрешение прерывания по переполнению таймера 0: 
    //0 — прерывание запрещено, 1 — прерывание разрешено.
    
    INTCON=(1<<GIE)|(1<<T0IE);
    //-------------------------------------------------------------------------------------------------
    TMR0=216;     //запускаем таймер при этом пропускаются два машинных цикла
    
}







void main(void) {
    Port_Init();
    timer_init();
    //ledprint(1234);       //выводим цифру 
    
    while(1)
    {
        for(int j=0;j<9999;j++)
        {
            ledprint(j);            //в цикле выводим цифры
            __delay_ms(delay);
        }
    }
}
