#include<lpc21xx.h>
int RS=0X10000000;
int RW=0X20000000;
int E =0X40000000;
void delay()
{
int i;
for(i=0;i<2000000;i++);
}
void lcdcmd(int cmd)
{
IOPIN1=cmd;
IOCLR0=RS;
IOCLR0=RW;
IOSET0=E;
IOCLR0=E;
delay();
}
void initlcd()
{
lcdcmd(0X00380000);
lcdcmd(0X00010000);
lcdcmd(0X00800000);
lcdcmd(0X000E0000);
lcdcmd(0X00060000);
}
void LCDDATA(char C)
{
IOPIN1=C<<16;
IOSET0=RS;
IOCLR0=RW;
IOSET0=E;
IOCLR0=E;
delay();
}
 void init_serial(void)
 {
 PINSEL0=0X00050000;
 U1LCR=0X83;
 U1DLL=0XC3;
 U1DLM=0X00;
 U1LCR=0X03;
 }
void trans(char v)
 {
 U1THR=v;
 while(!(U1LSR&0X20));
 }
int main()
{
int i,j;
int V;
int A[4]={0XEF,0XDF,0XBF,0X7F};
int B[4]={0X0E,0X0D,0X0B,0X07};
char M[4][4]={{'1','2','3','4'},
			  {'5','6','7','8'},
			  {'A','B','C','D'},
			  {'E','F','G','H'}};
PINSEL0=0X00000000;
PINSEL1=0X00000000;
PINSEL2=0X00000000;
IODIR0= 0X700000F0;
IODIR1 =0X00FF0000;
//initlcd();
init_serial( );
while(1)
{
	delay();
	IOPIN0=0X0000000F;
	while((IOPIN0 & 0X0F)==0X0F)
	delay();

	for(i=0;i<4;i++)
	{
		IOPIN0=A[i];
		V=(IOPIN0 & 0X0F);
		if(V!=0X0F)
		{											  
			for(j=0;j<4;j++)
			{
				if(V==B[j])
					{
					
					trans(M[i][j]);
					delay();
					
					}		
			}
		}
	}

}

}

