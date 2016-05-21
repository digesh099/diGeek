  #include<lpc21xx.h>
  	
void uart_init()
{
	VPBDIV=0x02;
	PINSEL0=0x05;
	U0LCR=0X80;
	U0DLL=0Xc2;
	U0DLM=0x00;
	U0LCR=0X03;
	U0IER=0X01;

}
			
 void urt1(void)  __irq
{	  
	char ch;
 	//IOSET1=0x00003000;
	//while((U1LSR&0x01)!=0x01);
	ch=U1RBR;
	U1THR=ch;
	while((U1LSR&0x20)!=0x20);
	ch=U1IIR;
	VICVectAddr=0x00000000;
}

main()
{		 
	
	uart_init();
//	PINSEL0=0x00050000;
	VICVectCntl0=0x00000027;
	VICVectAddr0=(unsigned)urt1;
	VICIntEnable=0x00000080;
 	while(1);

}

