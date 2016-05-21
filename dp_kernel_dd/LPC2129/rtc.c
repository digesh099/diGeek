#include<lpc21xx.h>
#include<string.h>
#include<stdio.h>
//#include<conio.h>
#include<math.h>

void serial_init(void);
void trans(char );
char rece(void);

bin(int h)
{
int p=0,q,r,bi[20];

while(h>0)
{
	bi[p++]=h%10;
	h=h/10;
	}
	q=p-1;
	r=0;
	while(q>=0)
	{
		r=r+(bi[q]*pow(2,q));
		q--;
		}

return(r);
}
int main()
{


VPBDIV=0x00000002;				    
PREINT=0x00000392;
PREFRAC=0x00004380;
CCR=0x00000001;
	
while(1)
{	
	serial_init();
	bin(HOUR);	
	trans(HOUR+0x30);
	trans(':');
	bin(MIN);
	trans(MIN+0x30);
	trans(':');
	bin(SEC);
	trans(SEC+0x30);
//	trans(-38);
	trans('\n');
	
}
 }
void serial_init(void)
{
	VPBDIV=0x02;
	PINSEL0=0x00050000;
	U1LCR=0x83;
	U1DLM=0x00;
	U1DLL=0xC3;
	U1LCR=0x03;
}
void trans(char val)
{
	U1THR=val;
	while((U1LSR & 0X20)!=0X20);
}
char rece(void)
{
	while((U1LSR & 0X01)!=0X01);
	return U1RBR;
}			