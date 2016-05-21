		 
		 
		 
#include<lpc21xx.h>

int VAR;

void delay()
{
int i;
for(i=0;i<3000000;i++);
}

void cmd(char ch)
{  IOCLR1=0x00ff0000;
  IOSET1=ch<<16;
  IOCLR0=0x10000000;
  IOCLR0=0x20000000;
  IOSET0=0x40000000;
  IOCLR0=0x40000000;
  delay();
}

void lcdint()
{
 cmd(0x38);
 cmd(0x01);
 cmd(0x0e);
 cmd(0x06);
 cmd(0x80);
}

void display(char ch)
{
 IOCLR1=0x00ff0000;
 IOSET1=ch<<16;
 IOSET0=0x10000000;
 IOCLR0=0x20000000;
 IOSET0=0x40000000;
 IOCLR0=0x40000000;
 delay();
}

main()
{ 
	PINSEL0=0x00000000;
 	PINSEL1=0x00000000;
  	PINSEL2=0x00000000;

 IODIR1=0x00ff0000;
 IODIR0=0X700000f0;

  lcdint();
  while(1)
  {
 IOPIN0=0X0000000F;

 
 while((IOPIN0 & 0X0F)==0X0F)
 delay();
 IOPIN0=0XEF;
 VAR=IOPIN0&0X0F;
 switch(VAR)
{
 case 0x0E:display('0');
 			break;
 case 0x0D:display('1');
 			break;
 case 0x0B:display('2');
 			break;
 case 0x07:display('3');
 			break;
 }

  IOPIN0=0XDF;
 VAR=IOPIN0&0X0F;

 switch(VAR)
{
 case 0x0E:display('4');
 			break;
 case 0x0D:display('5');
 			break;
 case 0x0B:display('6');
 			break;
 case 0x07:display('7');
 			break;
 }

  IOPIN0=0XBF;
 VAR=IOPIN0&0X0F;
 switch(VAR)
{
 case 0x0E:display('8');
 			break;
 case 0x0D:display('9');
 			break;
 case 0x0B:display('A');
 			break;
 case 0x07:display('B');
 			break;
 }

  IOPIN0=0X7F;
 VAR=IOPIN0&0X0F;
 switch(VAR)
{
 case 0x0E:display('C');
 			break;
 case 0x0D:display('D');
 			break;
 case 0x0B:display('E');
 			break;
 case 0x07:display('F');
 			break;
}


}
}