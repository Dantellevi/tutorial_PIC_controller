#include <xc.h>

#define _XTAL_FREQ 4000000

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = XT   // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF  // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF   // Low-Voltage In-Circuit Serial Programming Enable bit
#pragma config CPD = OFF   // Data EEPROM Memory Code Protection bit 
#pragma config WRT = OFF   // Flash Program Memory Write Enable bits 
#pragma config CP = OFF    // Flash Program Memory Code Protection bit

#define Val_DREG 10000

void TIM_CallBack(void);


void interrupt timer1()
{
   TIM_CallBack();
   TMR1=0x0000;
   TMR1IF=0;
}




void Port_Init(void)
{
    TRISA0=1;
    PORTAbits.RA0=0;
    
    TRISB0=0;
    PORTBbits.RB0=0;
    
}


unsigned char check_button(void)
{
    unsigned char result=0;
    unsigned int butcount=0;
    
    while(!RA0)
    {
        
        if(butcount<Val_DREG)
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




void Timer_Init(void)
{
    /*
     Расчет таймера :
     *  выберем делитель на 4
     * 
     * (4000000/4)/8=125000
     * 
     * ttic=1/125000=8мкс      -один тик таймера равен 1мкс
     * 
     *t- необходимое расчитываемое время: 100мс
     * 
     * количество тиков необходимое для отсчета 100мс:
     * n=t/ttic=200мс/4мкс=50000
     * 
     */
    
    //=================================Устанавливаем предделитель на 8=====================
    T1CKPS0=1;
    T1CKPS1=1;
    
    //=====================================================================================
    //=================================Вкл. тактирование таймера============================
    T1OSCEN=1;
    TMR1CS=0;       //работаем от внутреннего источника т.е. Fcpu/4
    
    GIE=1;      //вкл. глобальные прерывания
    TMR1IE=1;       //вкл. перерывания по переполнению
    PEIE=1;
    TMR1=0x0000;
    
    
    TMR1ON=1;       //включаем таймер
    
}


void Set_Timer_Value(unsigned int value)
{
    
}



/*
 ===========================Функция вызываемая при срабатывании прерывания по таймеру по переполнению===============
 */
void TIM_CallBack(void)
{
    PORTB^=(1<<0);
}


void main(void) {
   
    Port_Init();
    Timer_Init();
    
    while(1)
    {
        
    }
}
