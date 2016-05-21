

		#include<lpc21xx.h>
		#include<string.h>

			  
			  void init_serial(void);
			  int trans(char);
			   int rece(void);
		main()
		{
			char str[20]="\n enter the name \n";
			char v1[25]="\n enter the password \n";
			char a[]="\n correct \n";
			char b[]="\n incorrect \n";
			char d[]="student";
			char e[]="indian";
			char f[100];


			int i;
			
			  char ch,c[10];

			init_serial();
			while(1)
			{

			for(i=0;str[i]!='\0';i++)
			{
			trans(str[i]);
			 }
			 i=0;

				do
				{
				ch=rece();
				trans('ch');
				c[i]=ch;
				i++;
			 }while(ch!=0x0d);
				c[i-1]='\0';

			 for(i=0;v1[i]!='\0';i++)
			 trans(v1[i]);

			   i=0;
			   do
			   {
			   ch=rece();
			   trans('*');
			   f[i]=ch;
			   i++;
			   }
			   while(ch!=0x0d);
			   f[i-1]='\0';

			   if((strcmp("student",c)==0) && (strcmp("indian",f)==0))
				  {
				  for(i=0;a[i]!='\0';i++)
				  	trans(a[i]);
					}

					else
					{
					for(i=0;b[i]!='\0';i++)
					trans(b[i]);
					}

			 }

			 }




				  void init_serial(void)
				 
				 {	
					VPBDIV=0x02; 
				    PINSEL0=0x00050000;
				  	U1LCR=0x83;
					U1DLL=0xc3;
					U1DLM=0x00;
					U1LCR=0x03;
				  }

					int trans(char v)
					{
					U1THR=v;
					while(!(U1LSR&0x20));
					}	
					
					int rece()
						{
						while(!(U1LSR&0x01));
						return(U1RBR);
						} 
