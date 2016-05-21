#include <lpc21xx.h>
#include <stdio.h>

void delay ()
{
int i;
for (i=1;i<300000;i++);
}

void cmd(int ch)
{
IOPIN1=ch;
IOCLR0=0x10000000;
IOCLR0=0x20000000;
IOSET0=0x40000000;
IOCLR0=0x40000000;
delay();
}
void lcd_init( )
{
cmd(0x00380000);
cmd(0x000c0000);
cmd(0x00060000);
cmd(0x00010000);
}
void data(char ch)
{
IOPIN1=(ch<<16);
IOSET0=0x10000000;
IOCLR0=0x20000000;
IOSET0=0x40000000;
IOCLR0=0x40000000;
delay();
}

main ()
{
int val;
char ch[10];
int i;
int a,b,c,d,e,f;
PINSEL2=0X00000000;
PINSEL1=0X00000000;
IODIR1=0X00FF0000;
IODIR0=0X70000000;
VPBDIV=0X02;
ADCR=0X00270601;
ADCR|=0X01000000;
lcd_init();
while(1)
{
do
{
val=ADDR;
}while((val& 0x80000000)==0);
val=((val>>6)&0x03ff);
sprintf(ch,"%d",val);
for(i=0;ch[i]!='\0';i++)
data(ch[i]);
cmd(0x00800000);
}
return 0;
 }