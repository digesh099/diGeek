#include <LPC21xx.H>

//-------------------------------------------------------------------------------------------------------------

//-----------------FXN  prototypes---------------------------------------------------------------
void start_s_eeprom(void);
void send_byte_s_eeprom(char);
char get_byte_s_eeprom(void);
void stop_s_eeprom(void);
void send_to_mem(char, char);
unsigned int get_from_mem(char);
void wait(void);
void waitl(void);
void wait2(void );
void acknowledge(void);

void cmd_wrt(char);
void dat_wrt(char);

//----------------------------------------------------------------------------------------------

//-----------------fxn to send data to serial eeprom
// give the adress and the data as the parametrs to the fxn
 
 void send_to_mem(char s_address, char s_data)
 {
    start_s_eeprom();             // sending start condition to eeprom 
    send_byte_s_eeprom(0xA0);     // A0 = 10100000 = sending device address word for write
    acknowledge();
    send_byte_s_eeprom(s_address); // sending data address
    acknowledge();
    send_byte_s_eeprom(s_data);   // sending data 
    acknowledge();
    stop_s_eeprom();              // sending stop condition to eeprom
	acknowledge();
	return;
    
 }

//---------------------------------------------------------------------------------

//------------------fxn to get the data back frm the serial eeprom
// just give the adress from where the data is to be retrieved

 unsigned int get_from_mem(char s_address)
 {
    char i = 0;
//------------dummy write seq----+ word address------------------------------------
    start_s_eeprom();             // sending start condition to eeprom 
    send_byte_s_eeprom(0XA0);     // sending A0 = 10100000 = device address word for write
    acknowledge();
    send_byte_s_eeprom(s_address); // sending data address
    acknowledge();
//-------------------dummy over----------------------------------------------------


    start_s_eeprom();
    send_byte_s_eeprom(0XA1);     // sending A1 =10100001 = device adress word for read
    acknowledge();
    i = get_byte_s_eeprom(); // sending data 
    acknowledge();
    stop_s_eeprom();              // sending stop condition to eeprom
	acknowledge();

    return(i); 
 }

//---------------------------------------------------------------------------------------

//----------------------fxn to transmit a byte to the eeprom 
//this fxn just send the 8 bits serialy on the SDA line
//this fnx does not store the data in eeprom but just transmits it, this fxn is used by the storing fxn
//just pass the byte to be transmitted as parameter to this fxn


 void send_byte_s_eeprom(char s_byte)
 {
    char temp = s_byte;
	int i;
    //char i ;

	
    for(i = 7 ; i >= 0 ; i--)
    {
        temp = s_byte;
        temp = temp >> i;
        temp = temp & 0X01;
        if(temp == 0)
		IOCLR0 = 0x00000001;    //P0.0 SDA=0
            //sda   =   0;
        else

	    IOSET0 = 0x00000001;      //P0.0 SDA=1
            //sda   =   1;
		IOSET0 = 0x00000002;	   //P0.1  SCLK=1
            //sclk   =   1;
        waitl();
		IOCLR0 = 0x00000002;	  //P0.1  SCLK=0
            //sclk   =   0; 
    }
	return;
 }

//-----------------------------------------------------------------------------------------------

//---------------------------fxn to receive 8 bits serialy from sda line
// this is not a fxn to read from eeprom
// it just receives 8 bits serialy and retuns the byte received to the calling fxn

 char get_byte_s_eeprom()
 {
    char temp, temp_h;
	int i;
	//char i;
    temp = 0;
    temp_h = 1;	
	IOSET0 = 0x00000001;      //P0.0 SDA=1
    //sda = 1;    // making SDA as input pin for microcontroller
	IOCLR0 = 0x00000002;	  //P0.1  SCLK=0
  	//sclk	=	0;
    for(i = 7; i >=0 ; i--)
    {
	IOSET0 = 0x00000002;	  //P0.1  SCLK=1
    //sclk = 1;
    
	if((IOPIN0 & 0x00000001) == 1)  
	    //if(sda == 1)
        {
            temp = temp | temp_h<<i ;                      
        }
        wait();
     IOCLR0 = 0x00000002;	  //P0.1  SCLK=0
	//sclk = 0;
    }
	IOCLR0 = 0x00000002;	  //P0.1  SCLK=0
    //sclk = 0;
    return(temp);
 }

//-------------------------------------------------------------------------------------------

//------------------------------------------------fxn to send the start condition 

 void start_s_eeprom()
 {
    IOSET0 = 0x00000001;      //P0.0 SDA=1
    //sda     =   1;
	IOSET0 = 0x00000002;	  //P0.1  SCLK=1

    //sclk    =   1;
    waitl();
	IOCLR0 = 0x00000001;      //P0.0 SDA=0
	//sda     =   0;
	IOCLR0 = 0x00000002;	  //P0.1  SCLK=0
	//sclk    =   0;  
	return; 

 }

//---------------------------------------------------------------------------------------------

//------------------------------fxn to send stop condition

 void stop_s_eeprom()
 {
    IOCLR0 = 0x00000001;      //P0.0 SDA=0
    //sda     =   0;
	IOSET0 = 0x00000002;	  //P0.1  SCLK=1
    //sclk    =   1;
    waitl();
	IOSET0 = 0x00000001;      //P0.0 SDA=1
    //sda     =   1;
	IOCLR0 = 0x00000002;	  //P0.1  SCLK=0
    //sclk    =   0;
	return;   
 }

//-----------------------------------------------------------------------------------------------

//-------------------------------------fxn for acknowledging the eeprom
// this fxn actualy does not read the acknowledge signal
// it just waits for sufficient time and assumes that the eeprom has given tha ack by the time the wait gets over

 void acknowledge()
 {
	IOSET0 = 0x00000001;      //P0.0 SDA=1
	waitl();
   	IOSET0 = 0x00000008;	  //P0.3   led
	waitl();
 	IOSET0 = 0x00000002;	  //P0.1  SCLK=1
 	//sclk = 1;
   	waitl();
	IOCLR0 = 0x00000002;	  //P0.1  SCLK=0




	//sclk = 0;

	return;
 }

//-------------------------------------------------------------------------------------------------

//-------a small delay fxn to ensure the line settels down after transition

 void wait()
 {
  int i;
    for(i=0;i<=3000;i++)
		i++;
    return;
 }
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------

  void waitl()
 {
  int i;
    for(i=0;i<=59000;i++)
		i++;
    return;
 }

  void wait2()
  {
  int i;
    for(i=0;i<=9999000;i++)
		i++;
    return;
 }
//--------------------------------------------------------------------------------------------------

//--------------------------Command to LCD

void cmd_wrt(char ch)
{
            IOCLR1 = 0x00ff0000;
			IOCLR0 = 0x10000000;    // rs =0 p0.28 
			IOCLR0 = 0x20000000;    // rw =0 p0.29
			
			IOSET0 = 0x40000000;    // en=1  p0.30
			IOSET1 = ch<<16;
			waitl();
			IOCLR0 = 0x40000000;    //en=0   p0.30
			waitl();

}
 

//--------------------------------------------------------------------------------------------------

//--------------------------Data to LCD
 
void dat_wrt(char ch)
{
 			IOCLR1 = 0x00ff0000;
			IOSET0 = 0x10000000;	 // rs =1 p0.28
			IOCLR0 = 0x20000000;     // rw =0 p0.29 
			
 			IOSET0 = 0x40000000;     // en=1  p0.30
 			IOSET1 = ch<<16;
 			waitl();
 			IOCLR0 = 0x40000000;  //en=0   p0.30
			
}
void Lcdinit()

{
        cmd_wrt(0x38);
 		wait();
 		cmd_wrt(0x0e);
 		wait();
 		cmd_wrt(0x01);
 		wait();
  		cmd_wrt(0x06);
 		wait();
}


//-------------------------------------------------------------------------------------------------

//---------------------------------- MY MAIN PROGRAM

int main ()
{
	 unsigned char k[]="Writing data....";
	 unsigned char m[]="Reading data....";
	 unsigned char d[]="I2C by PHILIPS";
	 unsigned char a[]="   Thank you    ";
	 unsigned char i,j,l;
	 unsigned char c;
	 PINSEL0 = 0X00000000;
	 PINSEL1 = 0X00000000;   
	 PINSEL2 = 0X00000000;
	 IODIR0 = 0X7000000f;
	 IODIR1 = 0X00ff0000;
	 Lcdinit();
	 cmd_wrt(0x80);
 	 waitl();
	 	for(l=0; k[l]!='\0'; l++)
		    dat_wrt(k[l]);
     
for(i=0;d[i]!='\0';i++)     		//for writing data on to i2c memory
	{
	 send_to_mem(i,d[i]);
	 wait();
	 }

       // Lcdinit();			     	 // for initializing LCD

		cmd_wrt(0x01);
		cmd_wrt(0x80);
		for(j=0; m[j]!='\0'; j++)		 // reading display on LCD
		dat_wrt(m[j]);
	    
		//Lcdinit();			     	 // for initializing LCD
		cmd_wrt(0xc0);
 	    wait();

for(i=0;i<=13;i++)			// for reading data from i2c ,am sending its address
	{
	c=get_from_mem(i);
	dat_wrt(c);			// displaying the return value(ASCII)  to LCD
	}
wait2();
     cmd_wrt(0x01);
	cmd_wrt(0x80);
 	

	for(l=0; a[l]!='\0'; l++)
                dat_wrt(a[l]);
				

  
   while(1)
   {
   	 IOSET0=0x00000004;
	wait2();
	 IOCLR0=0x00000004;
   }

}

//---------------------------End of main
