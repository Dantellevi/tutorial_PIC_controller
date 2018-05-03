/*
 Протокол NEC используетсяя в пультах 
 * дистанционного управления 
 * для контроля и регулировки систем
 */
#include "Main.h"
//------------------------------------
unsigned int per1;

//------------------------------------

void interrupt isr(void)
{
    if(TMR1IE && TMR1IF)        //проверяем произошло ли прерывания по переполнению таймера
    {
        RA3=1;//уст. высокий уровень
        TMR1=0x0000;//сбрас. таймер
        TMR1IF=0;   //сбрасывает флаг прерывания
    }
    if(CCP1IF)                  //проверяем произошло ли прерывание модуля CCP по захвату
    {
        RA1=1;//устанавливаем высокий лог. уровень
        CCP1IF=0;//сбрасываем флаг прерываний
    }
    
    if(CCP2IF)
    {
        RA2=1;
        per1+=20;
        CCPR2 = per1;
        CCPR1 = per1>>1; //Use the bit shift to divide by 2 to speed up the operation
        if(per1>=2000) per1=80;
        CCP2IF=0;
    }
    
}


void main(void) {
    
    TRISA=0x00;
    PORTA=0x00;
    
    //=========================Разрешение прерывания как от первого так и от второго модуля====================
    CCP1IE=1;
    CCP2IE=1;
    //=========================================================================================================
    CCP1CON=0x0A; //вкл. Compare Mode
    //CCP2CON=0x0A;
    CCP2CON=0x0B;//compare mode CCP with trigger special event
    
    
    //CCPR1=0x4000;   //прерывания произойдут при четверти счета
    //CCPR2=0x8000;   // прерывания 2-ого модуля произойдут при половине счета
    
    per1=100;
    CCPR1=50;
    CCPR2=per1;
    
    
    CCP1IF=0;//сбрасываем флаг прерывания 
    CCP2IF=0;//сбрасываем флаг прерывания 
    
    T1CKPS0=1;  //предделитель равен 8  (4000000/4/65536)/8)=1.9Hz
    T1CKPS1=1;
    
    TMR1CS=0;//выбор тактирования
    TMR1IE=1;    //разрышение прерывания таймера
    
    GIE=0x1;//вкл. глобальные прерывания
    PEIE=0x1;   //прерывания по переферии
    TMR1ON=1;//вкл. таймер
    
    
    
    
    
    
    while(1)
    {
       
    }
}