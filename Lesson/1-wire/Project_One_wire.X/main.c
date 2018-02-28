
#include "Main.h"




void main(void) {
   
    char s=USART_Init(9600);
    Usart_PrintString("Hello User!!!\r\n");
    
    while(1)
    {
        start_meas();
	 __delay_ms(1000);
	 read_meas();
	 __delay_ms(1000);
    }
    
}
