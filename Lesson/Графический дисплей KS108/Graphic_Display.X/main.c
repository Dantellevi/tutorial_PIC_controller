#include "Main.h"

void main(void) {
   
    GLDKS108_Init();
    GLDKS108_Clear();
    GLD_Draw_Line(10,10,20,20);
    
    //GLD_Draw_Rectangle(60,30,20,60);
    //GLD_Draw_Ellipse(40,70,20);
    char buf[40]="HELLO МИР\0";
    GLD_print_string(0,0,(char*)buf,sizeof(buf)-1);
    
    while(1)
    {
        
    }
}
