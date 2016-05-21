#include<lpc21xx.h>
void delay()
{
  int i;
  for(i=0;i<30000;i++);
}

main( )
{ 
  int i,j; 
  int a[4]={0x90,0xc0,0x60,0x30};
  PINSEL0=0x00000000;
  IODIR0=0X0000000F;
  delay();
  while(1)
  {
  for(i=0;i<=25;j++)
  { 
    for(j=3;j<=0;j--)
	 {
	   IOSET0=a[j];
	   delay();
	   IOCLR0=a[j];
	   delay();
	 }
   }
   }
}