#include<lpc21xx.h>
#include<stdio.h>

	 void delay()
{
int i;
for(i=0;i<5000000;i++);
}
void delay1()
{
int i;
for(i=0;i<300000;i++);
}



void cmd(char ch)
{
IOCLR1=0X00FF0000;		  
IOSET1=ch<<16;
IOCLR0=0X10000000;
IOCLR0=0X20000000;
IOSET0=0X40000000;
IOCLR0=0X40000000;
delay();
}
void lcd_init()
{
cmd(0x38);
cmd(0x01);
cmd(0x0e);
cmd(0x06);
cmd(0x80);
}
void data(char ch)
{
IOCLR1=0X00FF0000;
IOSET1=ch<<16;
IOSET0=0X10000000;
IOCLR0=0X20000000;
IOSET0=0X40000000;
IOCLR0=0X40000000;
delay();
}

int  keypad()
{
int VAR;
int i;
while(1)
{
 IOPIN0=0X0F;



while((IOPIN0 & 0X0F)==0X0F)
{
 	delay();
}

 IOPIN0=0XEF;
 VAR=IOPIN0 & 0X0F;
 switch(VAR)
 {
 case 0x0e:i=i*10+0;
	data('0');
           
            break;
  case 0x0d: 
i=i*10+1;data('1');
            
            break;
  case 0x0b:i=i*10+2; data('2');
          
            break;
 case 0x07:i=i*10+3; data('3');
          
            break;
  }

   IOPIN0=0XDF;
 VAR=IOPIN0 & 0X0F;
 switch(VAR)
 {
 case 0x0e: i=i*10+4;data('4');
			
            break;
  case 0x0d: i=i*10+5;data('5');
            
            break;
  case 0x0b:i=i*10+6; data('6');
            
            break;
 case 0x07:i=i*10+7; data('7');
           
            break;
  }

  IOPIN0=0XBF;
 VAR=IOPIN0 & 0X0F;
 switch(VAR)
 {
 case 0x0e:i=i*10+8; data('8');
           
            break;
  case 0x0d:i=i*10+9; data('9');
            
            break;
  case 0x0b: data (':');
             
			 return(i/7.2); 
            break;
 
            
        
  }

 /* IOPIN0=0X7F;
 VAR=IOPIN0 & 0X0F;
 switch(VAR)
 {
 case 0x0e:
 			//i=i*10+C; data('C');
            
            break;
  case 0x0d://i=i*10+D;
  			 data('D');
         
            break;
  case 0x0b://i=i*10+E; 
  			data('E');
           
            break;
 case 0x07: data(':');
            return(i/7.2);
			break;
           
  }	   */


}


}



	 
	   
																    
main()
{


char ch[4];

 int j;
int i=0;

 int step;
int a[4]={0x000c0000,0x00060000,0x00030000,0x00090000};
PINSEL0=0x00000000;
PINSEL2=0X00000000;
PINSEL1=0X00000000;
IODIR0=0X700f00f0;
IODIR1=0X00FF0000;

 lcd_init();



step=keypad();
   			 sprintf(ch,"%d",step);
			 for(i=0;ch[i]!='\0';i++)
			 data(ch[i]);
			

	
	    
		for(j=0;j<step;j++)
		{
		   for(i=0;i<4;i++)
		    {
	      IOSET0=a[i];
		  delay1();
		  IOCLR0=a[i];
		    }
	    }


  }


		