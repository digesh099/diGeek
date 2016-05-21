/* program to understand the usage of pre processor */

#include<stdio.h>
#define HARI

int main(void)
{
	int a = 10, b = 20, c;
	#ifdef HARI
	
	c = a + b;	
	printf("c = %d\n",c);
	
	#else
	printf("c = %d\n",c+2);
	#endif
	return 0;
}

