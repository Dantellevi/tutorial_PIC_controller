#include "lcd.h"
static void HiPin(void)	;
static void OutPin(void);
static void InPin(void)	;
void strob(void);
unsigned char check_Button(void);
static void Busy_flag(void);



static void HiPin(void)	
{
    DDDR |=((1<<DB7)|(1<<DB6)|(1<<DB5)|(1<<DB4));
	DPORT&=~((1<<DB7)|(1<<DB6)|(1<<DB5)|(1<<DB4));
}

static void OutPin(void)
{
    DDDR &=~((1<<DB7)|(1<<DB6)|(1<<DB5)|(1<<DB4));
	DPORT&=~((1<<DB7)|(1<<DB6)|(1<<DB5)|(1<<DB4));
}

static void InPin(void)	
{
    DDDR |=((1<<DB7)|(1<<DB6)|(1<<DB5)|(1<<DB4));
	DPORT|=(1<<DB7)|(1<<DB6)|(1<<DB5)|(1<<DB4);
}


void strob(void)
{
    CPORT|=(1<<E);
    __delay_ms(1);
    CPORT&=~(1<<E);
}

unsigned char check_Button(void)
{
    unsigned char result=0;
    unsigned int butcount=0;
    
    while(PORTB&(1<<RB7))
    {
        if(butcount<10)
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



static void Busy_flag(void)
{
    char i=1;
    
    while(i==1)
    {
        CPORT|=(1<<E);
        asm("nop");
		asm("nop");
        if(check_Button()==1)
        {
            i=0;
        }
        CPORT&=~(1<<E);//Âûêëþ÷èëè ñòðîá.
		asm("nop");
		asm("nop");
		strob();
		asm("nop");
		asm("nop");
        
    }
   CPORT&=~(1<<RW);
        
    
}

static void LCDcommand(char i)
{
    Busy_flag();
    Send_byte(i);
    
}
static void Send_byte(char i)
{
    OutPin();
    char higb=((i&0b11110000)>>4);
    char lowb =  (i&0b00001111);
    if ((higb&1)==1)
			{
				DPORT|=(1<<DB4);
			}
			higb=higb>>1;
			if ((higb&1)==1)
			{
				DPORT|=(1<<DB5);
			}
			higb=higb>>1;
			if ((higb&1)==1)
			{
				DPORT|=(1<<DB6);
			}
			higb=higb>>1;
			if ((higb&1)==1)
			{
				DPORT|=(1<<DB7);
			}
	
			strob();
			OutPin();
	
			if ((lowb&1)==1)
			{
				DPORT|=(1<<DB4);
			}
			lowb=lowb>>1;
			if ((lowb&1)==1)
			{
				DPORT|=(1<<DB5);
			}
			lowb=lowb>>1;
			if ((lowb&1)==1)
			{
				DPORT|=(1<<DB6);
			}
			lowb=lowb>>1;
			if ((lowb&1)==1)
			{
				DPORT|=(1<<DB7);
			}
	
			strob();
}






//========================================Основные функции для работы с дисплеем====================

void LCDinit(void)
{
    CDDR &=~((1<<RS)|(1<<E)|(1<<RW)); 
    CPORT&=~((1<<RS)|(1<<E)|(1<<RW));
    OutPin();
    
    char i=0;
    while (i!=3)
    {
        DPORT|=(0<<DB7)|(0<<DB6)|(1<<DB5)|(1<<DB4);
        strob();
		__delay_ms(5);
		i++;
    }
    
    
    Busy_flag();
	OutPin();
	DPORT|=(0<<DB7)|(0<<DB6)|(1<<DB5)|(0<<DB4);
	strob();
	LCDcommand(0b00101000);
    LCDcommand(0b1100);  
	LCDcommand(0b110);   
	LCDcommand(0b10);    
	LCDcommand(0b1);    
}




void LCDdata(char i)						
{
	Busy_flag();	//Ïðîâåðèì ñïåðâà ôëàã çàíÿòîñòè, à ñâîáîäåí ëè äèñïëåé?
	CPORT|=(1<<RS); //RS=1 ïîñûëàåì äàííûå â LCD
	Send_byte(i);
	CPORT&=~(1<<RS);//RS=0
}
void LCDdataXY (char a, char b,char c)	
{
	LCDGotoXY(b,c);
	LCDdata(a);
}
void LCDGotoXY(char x,char y)			
{
	 char Address;
	
	switch(y)
	{
		case 0: Address = LINE0+x; 
				break;
		case 1: Address = LINE1+x; 
				break;
		case 2: Address = LINE2+x;
				break;
		case 3: Address = LINE3+x;
				break;
		default: Address = LINE0+x;
	}
	
	LCDcommand(1<<7 | Address);
}



void LCDstringXY(char *i,char x,char y) 
{
	LCDGotoXY(x,y);
	while( *i )
	{
		LCDdata(*i++ );
	}
}
void LCDsendString(char *s)
{
	while( *s )
	{
		LCDdata(*s++ );
	}
	
}


void LCDputsIntGotoXY(int val,char x,char y)		
{
char str[40];
itoa(val,str,10);

LCDstringXY(str,x,y);

}

void LCDclear(void)			
{
	LCDcommand(0b1);
}