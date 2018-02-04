#include <xc.h>
#include "Main.h"


void Port_Init(void)
{
    TRISA=0x00;
    PORTA=0x00;
    
}

void main(void) {
   
    Port_Init();
    char status=USART_Init(9600);
    
    while(1)
    {
       //===============Проверка одиночной передачи===============
       //Transmit_char('A');
       //Transmit_char(0x0D);
       //Transmit_char(0x0A);
        //========================================================
        //Usart_PrintString("Hello WOrld!!!");
        if(USART_Read()=='1')
        {
            PORTAbits.RA0=1;
        }
        else
        {
            PORTAbits.RA0=0; 
        }
       
       __delay_ms(500);
        
       
    }
}
