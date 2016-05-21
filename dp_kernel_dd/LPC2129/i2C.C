#include<LPC21xx.H> 
void inti_lcd(void);
void lcd_data(char ch);
void I2CISR(void)__irq ;																			//I2C interrupt routine
void I2CTransferByte(unsigned int I2CAddr,unsigned char MemAddr,unsigned char count,unsigned char *ap);			//Background call to start master send and receive byte transfers
unsigned char 	message[6] = {'I','D','R','I','S'};													
unsigned char	messageIn[100];
unsigned char 	*I2CData,ch[10],
			 	I2Counter,
				I2CAddress,
				MemAddress,
				lock;		//Define Function prototypes and Global variables
int i,j;
int main(void)
{ 
unsigned int ch,p;
 inti_lcd();
lock = 0;									//Initilise the lock flag
VICVectCntl1 = 0x00000029;  				//select a priority slot for a given interrupt
VICVectAddr1 = (unsigned)I2CISR;			//pass the address of the IRQ into the VIC slot
VICIntEnable = 0x00000200;					//enable interrupt

//PINSEL0  	 = 0x50; 						//Switch GPIO to I2C pins
PINSEL0  	 = 0x00050050; 						//Switch GPIO to I2C pins
I2SCLH 		 = 100;						//Set bit rate for 300kbps
I2SCLL 		 = 100;

 //PINSEL0  	 = 0x00050050; 						//Switch GPIO to I2C pins
VPBDIV=0x02;
//U1LCR=0X00000083;
//U1DLL=0X000000C2; 
//U1LCR=0X00000003; // disable divisor access latch bit
/*while (!(U1LSR & 0x20));
 U1THR ='W';
 while (!(U1LSR & 0x20));
 U1THR ='A';
 while (!(U1LSR & 0x20));
 U1THR ='H';
 while (!(U1LSR & 0x20));
 U1THR ='I';
 while (!(U1LSR & 0x20));
 U1THR ='D';
 while (!(U1LSR & 0x20));
 U1THR ='R';
 while (!(U1LSR & 0x20));
 U1THR ='I';
 while (!(U1LSR & 0x20));
 U1THR ='S';	 */

 for(ch=0;ch<=1000000;ch++);
	
I2CTransferByte(0xA0,0,6,message);
 for(i=0;i<=2000000;i++);			//write data to the I2C Memory
for(ch=0;ch<=10000;ch++);
I2CTransferByte(0xA0,0,0,'\0');					//set address to zero
for(ch=0;ch<=10000;ch++);
I2CTransferByte(0xA1,0,6,messageIn);		//read back data

for(ch=0;ch<=10000;ch++);
for(p=0;p<5;p++)
{
 while (!(U1LSR & 0x20));
 U1THR =messageIn[p];
 for(ch=0;ch<=10000;ch++);
 }


while(1)
{
;
}
}


void I2CTransferByte(unsigned int I2CAddr,unsigned char MemAddr,unsigned char count,unsigned char *ap)
{


while(lock == 1)							//Wait for interrupt to signal end of I2C activity
{
;
}
lock 		= 1;                   			//Set I2C bus as active

I2CAddress 	= I2CAddr;						//Place address and data in Globals to be used by the interrupt
if(count >0)
{
I2CData  	= (unsigned char *)ap;
}
I2Counter	= count;
MemAddress	= MemAddr;
I2CONCLR 	= 0x000000FF;					//Clear all I2C settings
I2CONSET 	= 0x00000042; 					//Enable the I2C interface
I2CONSET 	= 0x00000020; 					//Start condition

}


void I2CISR (void)	__irq						//I2C interrupt routine
{
switch (I2STAT)								//Read result code and switch to next action
{
// Start and Send byte conditions

case ( 0x08):								//Start bit
I2CONCLR 	= 0x20;							//Clear start bit
I2DAT   	= I2CAddress; 					//Send address and write bit
break;

case (0x18):								//Slave address+W, ACK
I2DAT   	= MemAddress;					//Write Mem,ory start address to tx register
break;

case (0x20):								//Salve address +W, Not ACK
I2DAT   	= I2CAddress; 					//Resend address and write bi
break;

case (0x28):
if(I2Counter-->0)								//Data sent, Ack
{
I2DAT   	= *I2CData;						//Write data to tx register
I2CData++;
}
else
{
I2CONSET 	= 0x10;							//Stop condition
lock = 0;                       			//Signal end of I2C activity
}
break;

case (0x30)	:								//Data sent, NOT Ack
I2DAT   	= *I2CData;						//Write data to tx register
break;


//Receive byte conditions

case (0x40) :								//Slave Address +R, ACK
I2CONSET 	= 0x04;							//Enable ACK for data byte
break;

case (0x48) :								//Slave Address +R, Not Ack
I2CONSET 	= 0x20;							//Resend Start condition
break;

case (0x50) :								//Data Received, ACK 
if(--I2Counter>0)
{
 for(i=0;i<=1000000;i++);
*I2CData= I2DAT;
//for(i=0;i<10;i++)
ch[0]=I2DAT;
  //for(j=0;j<8;j++)
  lcd_data(ch[0]);
I2CData++;
}
else
{
I2CONSET 	= 0x10;							//Stop condition
lock 		= 0;                    		//Signal end of I2C activity							
}
break;

case (0x58):								//Data Received, Not Ack
I2CONSET 	= 0x20;							// Resend Start condition
break;

default :
break;

}

I2CONCLR 	= 0x08;							//Clear I2C interrupt flag
VICVectAddr = 0x00000000;					//Clear interrupt in 

}
