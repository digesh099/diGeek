#include<LPC21xx.h>
int rs =0X10000000	;
int rw =0X20000000	 ;
int e =0X40000000	  ;
void delay()
{
	int i;
	for(i=0;i<3000000;i++);
}
void lcdcmd(int cmd)
{
IOPIN1=cmd;
IOCLR0=rs;
IOCLR0=rw;
IOSET0=e;
IOCLR0=e;
delay();
}
void lcddata(int ch)
{
IOPIN1=ch<<16;
IOSET0=rs;
IOCLR0=rw;
IOSET0=e;
IOCLR0=e;
delay();
}
void initlcd()
{
int i,j;
char str[]="ISM TECH ";
PINSEL2=0X00000000;
PINSEL1=0X00000000;
IODIR1=0X00FF0000;
IODIR0=0X70000000;
lcdcmd(0X00380000);
lcdcmd(0X00010000);
lcdcmd(0X00800000);
lcdcmd(0X000E0000);
lcdcmd(0X00060000);
}

