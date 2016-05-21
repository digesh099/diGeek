#include<lpc21xx.h>

void delay()
{
int i;
for(i=0;i<300000;i++);
}

main()
{
int i,j;
int a[4]={0x0c,0x06,0x03,0x09};
PINSEL0=0X00000000;
IODIR0=0x0f0;

while(1)
{
	for(i=0;i<50;i++)
	{
		for(j=0;j<4;j++)
		{
		IOSET0=a[j];
		delay();
		IOCLR0=a[j];
		delay();
		}
	}
}
}
