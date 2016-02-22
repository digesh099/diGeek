#include<stdio.h>
#include<signal.h>
void fun(int signo)
{
	//printf("\n In handler fun %d\n",signo);
	//exit(0);
	return;
}
int i;
main()
{
	char *ptr="ism";


	
	signal(SIGSEGV,fun);
//	signal(SIGSEGV,SIG_DFL);
	
	  *(ptr+i)='j';
	  
	printf("hi \n");


}	
