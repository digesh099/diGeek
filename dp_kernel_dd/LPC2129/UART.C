#include<dos.h>
#include <stdio.h>
#include <conio.h>
#define PORT1 0x3F8

char mobile_no[11], msg[256];
char send_cmd[25]="AT+CMGS=\"";
char end_cmd[]   = "\"\r";
char pin[]="AT+CPIN=?\r";
char format[]="AT+CMGF=1\r";
char read_cmd[]="AT+CMGl=\"REC UNREAD\"\r";

uart_init()
{
	outportb(PORT1 + 1 , 0);
	outportb(PORT1 + 3 , 0x80);
	outportb(PORT1 + 0 , 0x0c);
	outportb(PORT1 + 1 , 0x00);
	outportb(PORT1 + 3 , 0x03);
	outportb(PORT1 + 2 , 0xC7);
	outportb(PORT1 + 4 , 0x0B);
	return;
}


send()
{
	int i;
	char c, ch,m;

	printf("\nEnter the mobile number:");
	scanf( "%s",mobile_no);
       ch=	getchar();
	printf("\nEnter the message to be sent:");
	gets(msg);
	for(i=0;send_cmd[i];i++)
	outportb(PORT1, send_cmd[i]);
	for(i=0;mobile_no[i];i++)
	outportb(PORT1, mobile_no[i]);
	for(i=0;end_cmd[i];i++)
	outportb(PORT1, end_cmd[i]);
	  outportb(PORT1, 0x0a);
		for(i=0;msg[i];i++)
		outportb(PORT1, msg[i]);

		outportb(PORT1, 0x1a);
		outportb(PORT1, 0x0a);
		do
		{
			c = inportb(PORT1 + 5);
			if (c & 1)
				ch = inportb(PORT1);
		}while(ch!='K');
		printf("\n message sent \n");
		return ;

}

read()
{
	int i,j;
	char c, ch;
	char a[50];
	
	for(i=0;read_cmd[i];i++)
	outportb(PORT1, read_cmd[i]);
	j=0;
	do
	{
		c = inportb(PORT1 + 5);
		if (c & 1)
		{
			ch = inportb(PORT1);
			a[j++]=ch;
		}
		}while(ch!='K');

	a[j-2]='\0';

	printf("\nthe received message is\n");
	for(j=0;a[j];j++)
	printf("%c", a[j]);
	return;
}


	
	
void main(void)
{
	int ch,i;
	uart_init();
	for(i=0;pin[i];i++)
	outportb(PORT1, pin[i]);
	for(i=0;format[i];i++)
	outportb(PORT1, format[i]);
	clrscr();
	while(1)
	{

		printf("\nEnter the choice\n 1.Send SMS \n 2.Read SMS \n 3.Exit \n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: send(); break;
			case 2: read(); break;
			case 3: exit(0);
			default: printf("\n in valid entry\n");
		}

	}
}

		
