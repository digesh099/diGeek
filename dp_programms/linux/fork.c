#include<stdio.h>
int ret;

main()
{
	int a=5;
	ret=fork();
	if(ret==0)
	{a++;
		printf("\nHELLO\n %d",a);
		
	}
	else
	{
		printf("\nBYE\n %d",a);
	}
}
		
