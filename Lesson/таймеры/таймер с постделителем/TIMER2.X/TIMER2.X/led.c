#include "led.h"
//--------------------------------------------------------------
unsigned char n_count=0, R1=0, R2=0, R3=0, R4=0;
extern unsigned int TIM1_Count;
//--------------------------------------------------------------
void segchar (unsigned int seg)
{
  switch (seg)
  {
    case 1:
      PORTB = 0b11111001;
      break;
    case 2:
      PORTB = 0b10100100;
      break;
    case 3:
      PORTB = 0b10110000;
      break;
    case 4:
      PORTB = 0b10011001;
      break;
    case 5:
      PORTB = 0b10010010;
      break;
    case 6:
      PORTB = 0b10000010;
      break;
    case 7:
      PORTB = 0b11111000;
      break;
    case 8:
      PORTB = 0b10000000;
      break;
    case 9:
      PORTB = 0b10010000;
      break;
    case 0:
      PORTB = 0b11000000;
      break;
  }
}
//--------------------------------------------------------------
void ledprint(unsigned int number)
{
  R1 = number%10;
  R2 = number%100/10;
  R3 = number%1000/100;
  R4 = number/1000;
}
//--------------------------------------------
void TIM0_Callback(void)
{
  ledprint(TIM1_Count);
  if(n_count==0)
  {
    PORTCbits.RC3 = 0;
    segchar(R1);
    PORTCbits.RC0 = 1;
  }
  else if(n_count==1)
  {
    PORTCbits.RC0 = 0;
    segchar(R2);
    PORTCbits.RC1 = 1;
  }
  else if(n_count==2)
  {
    PORTCbits.RC1 = 0;
    segchar(R3);
    PORTCbits.RC2 = 1;
  }
  else if(n_count==3)
  {
    PORTCbits.RC2 = 0;
    segchar(R4);
    PORTCbits.RC3 = 1;
  }
  n_count++;
  if (n_count>3) n_count=0;
}
//--------------------------------------------
