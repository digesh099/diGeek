#include<stdio.h>
char * value( );

int main()
{
	char *ret; 
	printf("in main function \n");
	ret = value();
	printf("ret value of the function is = %s\n",ret);
	return 0;
}


char * value()
{
	static char *r = "hari";
	return r;
}
