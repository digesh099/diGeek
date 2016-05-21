#include<lpc21xx.h>
#include<stdio.h>


void delay()
{
int i;
	for(i=0;i<3000000;i++);
}

void delay1()
{
int i;
	for(i=0;i<300000;i++);
}
void cmd(int ch)
{
	IOCLR1=0X00FF0000;
	IOSET1=ch<<16;
	IOCLR0=0X30000000;
	IOSET0=0X40000000;
	IOCLR0=0X40000000;
	delay();
}

void lcd_init()
{
	cmd(0x38);
	cmd(0x01);
	cmd(0xe);
	cmd(0x6);
	cmd(0x80);
}

void data(char ch)
{
	IOCLR1=0X00FF0000;
	IOSET1=ch<<16;
	IOCLR0=0X20000000;
	IOSET0=0X50000000;
	IOCLR0=0X40000000;
	delay();
}

int keypad()
{
	
	int i=0,var;
	char ch[10];
	while(1)
	{
	IOPIN0=0X0F;
	while((IOPIN0&0XF)==0xf);

	IOPIN0=0XEF;
	var=IOPIN0&0XF;
	switch(var)
	{	
		case 0xe:i=i*10+0;
				 data('0');	
				break;
		case 0xd:i=i*10+1;
				 data('1');
				break;
		case 0xb:i=i*10+2;
				 data('2');
				break;
		case 0x7:i=i*10+3;
				 data('3');
				break;
	}
	
	
	
	IOPIN0=0XdF;
	var=IOPIN0&0XF;
	switch(var)
	{	
		case 0xe:i=i*10+4;
				 data('4');	
				break;
		case 0xd:i=i*10+5;
				 data('5');
				break;
		case 0xb:i=i*10+6;
				 data('6');
				break;
		case 0x7:i=i*10+7;
				 data('7');
				break;
	}
	
	
	IOPIN0=0XbF;
	var=IOPIN0&0XF;
	switch(var)
	{	
		case 0xe:i=i*10+8;
				 data('8');	
				break;
		case 0xd:i=i*10+9;
				 data('9');
				break;
		case 0xb:data(0x1a);
				 data(0xfa);
				 data(0xf8);
				 data(0xf9);
				 
				 
				 			
				 return (i/7.2);
				break;
	
	}
	

		}
}
main()
{	
 	int i,n,j,a[]={0xc00,0x600,0x300,0x900};
	char ch[10];
 	PINSEL0=0x00000000;
 	PINSEL1=0X0;
 	PINSEL2=0X0;
 	IODIR0=0x70000ff0;
 	IODIR1=0X00FF0000;

 	lcd_init();

  	while(1)
  	{
 		n=keypad();

		sprintf(ch,"%d",n);
		for(j=0;ch[j]!='\0';j++)
		data(ch[j]);

 		for(j=0;j<n;j++)
 		{
 			for(i=0;i<4;i++)
  			{
 				IOSET0=a[i];
 				delay1();
 				IOCLR0=a[i];
 				delay1();
  			 }
  		}
 	}
}