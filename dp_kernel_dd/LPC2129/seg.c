#include<lpc21xx.h>
delay()
{
int i;
for(i=0;i<100000;i++);
}
main()
{
int i,A[]={0X000F4000,0X000FF900,0X000FA400,0X000FB000,0X000F1900};
PINSEL0=0x00000000;
PINSEL1=0x00000000;
IODIR0=0x000FFF00;
while(1)
{
for(i=0;i<=4;i++)
{
delay();
IOSET0=A[i];
delay();
IOCLR0=A[i];
delay();
}
}
}


