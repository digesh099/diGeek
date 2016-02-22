#include<stdio.h>
main()
{
	int a;
	printf("enter the no. \n");
	scanf("%d",&a);
	if((a&(a-1))==0)
	{
		printf("no is power of 2\n");
	}
	else
	{
		printf("no is not power of 2\n");
	}
}
