							 #include<lpc21xx.h>
void delay(unsigned int num)
{
int i;
while(num--)
for(i=0;i<1000;i++);
}
int main()
{
PINSEL2=0X00000000;
IODIR1=0X01fe0000;
while(1)
{
IOCLR1=0X00000000;
delay(100);
IOSET1=0X00800000;
delay(100);
IOCLR1=0X00800000;
delay(100);
IOSET1=0X00400000;
delay(100);
IOCLR1=0X00400000;
delay(100);
IOSET1=0X00200000;
delay(100);
IOCLR1=0X00200000;
delay(100);
IOSET1=0X00100000;
delay(100);
IOCLR1=0X00100000;
delay(100);
IOSET1=0X00080000;
delay(100);
IOCLR1=0X00080000;
delay(100);
IOSET1=0X00040000;
delay(100);
IOCLR1=0X00040000;
delay(100);
IOSET1=0X00020000;
delay(100);
IOCLR1=0X00020000;
delay(100);
IOSET1=0X00010000;
delay(100);
IOCLR1=0X00010000;
delay(100);
}
}







