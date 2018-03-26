#include "main.h"
//--------------------------------------------------------------
unsigned int TIM1_Count=0;
unsigned char ncnt=0;
//--------------------------------------------------------------
void interrupt isr(void)
{
  if(TMR0IE&&TMR0IF)
  {
    TIM0_Callback();
    T0IF=0;
  }
  else if(TMR2IE&&TMR2IF)
  {
    TMR2IF=0;
    ncnt++;
    if(ncnt>25)
    {
      ncnt=0;
      TIM1_Count++;
      if(TIM1_Count>9999) TIM1_Count=0;
    }
  }
}
//--------------------------------------------
void main(void) {
  TRISB = 0x00;
  PORTB = 0xFF;
  TRISC = 0x00;
  PORTC = 0x00;
  OPTION_REG=0b00000010; //Prescaler 8
  T0IE=1;
  GIE=1;
  PEIE=1;
  TOUTPS3=1; //Prescaler Out 10
  TOUTPS2=0;
  TOUTPS1=0;
  TOUTPS0=1;
  T2CKPS0=1;//Postcaler In 16
  T2CKPS1=1;
  PR2=0xF9; // 249 - 1000000/10/16/250 = 25Hz
  TMR2IE=1;
  TMR2ON=1;
  TMR0=0;
  while(1)
  {
  }
}
