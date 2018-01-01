/*
 * File:   main.c
 * Author: Dante_L_Levi
 *
 * Created on 24 ������� 2017 �., 20:23
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



//=======================������� ��� ������� ��������======================
#define PS2 2
#define PS1 1
#define PS0 0

#define GIE 7
#define T0IE 5

//-----------------------------------------------------------------

unsigned int TIM0_count=0;


//------------------���������� ���������� �� ������������--------------------
void interrupt timer0()
{
    //������ �������� ���� � � ����������� �� �������� ����� ��������� ��������� �� ����
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
    
TIM0_count++;           //�������������� ���������� ���������� �������
if(TIM0_count>3999)         //���������� ���������� � ����
{
  TIM0_count=0;
}
//T0IF (TMR0 Overflow Interrupt Flag) � ���� ���������� �� ������������ ������� 0:
//0 � �������� ���������� ���, 1 � ��������� ������������ �������� ������� 0 (������������ ����������).
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
    //������� ����� �� 4��� � � ������ ���� ������ � PIC ������������ �������� �����
    
    OPTION_REG=(1<<PS2)|(1<<PS1)|(1<<PS0);      //�������� ������������ �� 256 (111)-1000000/256=3.9���
    //�� ��� ��� ������ ����� ������� �� 0 �� 255, �� �� ��� ��� ����� �� 256 � �������� �������������� 15,3 ��
    //--------------------------------------------------------------------------------------------------
    
    //GIE (Global Interrupt Enable) � 
    //���������� ���������� ����������: 
    //0 � ��� ���������� ���������, 
    //1 � ��� ��������������� ���������� ���������.
    //----------------------------------------------------------
    //T0IE (TMR0 Overflow Interrupt Enable) � 
    //���������� ���������� �� ������������ ������� 0: 
    //0 � ���������� ���������, 1 � ���������� ���������.
    
    INTCON=(1<<GIE)|(1<<T0IE);
    //-------------------------------------------------------------------------------------------------
    TMR0=0;     //��������� ������ ��� ���� ������������ ��� �������� �����
    
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
