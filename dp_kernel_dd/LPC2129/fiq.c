#include<lpc21xx.h>
int flag = 0;
void delay1(void)
{
	int i;
	char k;
	for(k=0;k<=8;k++)
	{
		for(i=0;i<=400000;i++) ;  //400000
	}
}
void fun(void)  __irq;
void fiq_init(void) 
{
	VICVectCntl0=  0x0000002f;
	VICVectAddr0=(unsigned)fun();							//Enable a Vic Channel as FIQ
	VICIntEnable=0x00008000;
	EXTMODE         = 0x0B;
	EXTPOLAR        = 0x00;
	
}		



void fun(void)	__irq
{
		IOCLR0	=	0x00000001;
 		EXTINT  	= 0x00000002;
		flag = 1;
		VICVectAddr=0x0000000;
}
int main()
{
	PINSEL0 = 	0x20000000;      
	IODIR0	=	0x00000001;
	fiq_init();
	IOSET0	=	0x00000001;
	while(1)
	{
	 	if(flag == 1)
		{
			flag = 0;
			delay1();
			delay1();
			delay1();
			delay1();
			delay1();
			delay1();

			IOSET0	=	0x00000001;
		}
	}
}								