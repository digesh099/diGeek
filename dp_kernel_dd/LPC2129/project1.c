#include<reg51.h>
sbit rs=P3^7;
sbit rw=P3^6;
sbit en=P3^5;
void msdelay(unsigned int i);
void lcdcmd(unsigned char val);
void lcdata(unsigned char val);

void serial()
{
TMOD=0x20;
SCON=0x50;
TH1=0xfd;
TR1=1;
}

void trans(char ch)
{
SBUF=ch;
while(TI!=1);
TI=0;
}

char rece()
{
char ch;
while(RI!=1);
RI=0;
ch=SBUF;
return ch;
}

 void lcdcmd(unsigned char val)
{
P0=val;
rs=0;
rw=0;
en=1;
msdelay(5);
en=0;
}

void lcdata(unsigned char val)
{
P0=val;
rs=1;
rw=0;
en=1;
msdelay(5);
en=0;

}

void msdelay(unsigned int i)
{
unsigned k,j;
for(k=0;k<i;k++)
for(j=0;j<50;j++);
}

int main()
{

int i;
int c;
char ch[]="AT+CMGS=\"9060019421\"\r";
char msg1[]="LONGITUDE: 1234567\r";
char msg2[]="LATTITUDE: 32165478\r";

char arr[]="VEHICLE TRACKING";
char brr[]="USING GOOGLE MAP";
char sent[]="message sent....";

lcdcmd(0x38);  
msdelay(250);
lcdcmd(0x0e);
msdelay(250);
lcdcmd(0x01);
msdelay(250);
lcdcmd(0x06);
msdelay(250);
serial();
	for(i=0;arr[i]!='\0';i++)
	{
	 lcdata(arr[i]);
	 msdelay(250);
	}

	lcdcmd(0xc0);
	for(i=0;brr[i]!='\0';i++)
	{
	lcdata(brr[i]);
	msdelay(250);
	}


	for(i=0;ch[i]!='\0';i++)
	trans(ch[i]);
	do
	{
	c=rece();
	}while(c!='>');

	for(i=0;msg1[i]!='\0';i++)
	trans(msg1[i]);

	do
	{
	c=rece();
	}while(c!='>');
	
	for(i=0;msg2[i]!='\0';i++)
	trans(msg2[i]);

	trans(0x1a);
	do
	{
	c=rece();
	}while(c!='K');

	for(i=0;sent[i]!='\0';i++)
		lcdata(sent[i]);
	return 0;

}

