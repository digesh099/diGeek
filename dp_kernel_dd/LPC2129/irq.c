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
void fiq_init(void) 
{
	VICIntSelect 	= 0x0002C000;							//Enable a Vic Channel as FIQ
	VICIntEnable	= 0x0002C000;
	EXTMODE         = 0x0B;
	EXTPOLAR        = 0x00;		
}
void FIQ_Handler (void)__irq
{
	IOCLR0	= 0x00000001;
 	EXTINT  	= 0x00000001;
	EXTINT  	= 0x00000002;
	flag          = 1;
}
int main()
{
	PINSEL0 = 	0x2000000C;      
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

			IOSET0	= 0x00000001;
		}
	}
}								