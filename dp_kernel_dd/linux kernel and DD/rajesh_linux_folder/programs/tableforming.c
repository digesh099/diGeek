#include<stdio.h>
main()
{
	int n,mul,i;
	printf("enter the value of number");
	scanf("%d",&n);
	for(i=1;i<=10;i++)
	{
		mul=n*i;
		printf("\n\n%d\tx%d\t=\t%d",n,i,mul);
	}
	return 0;
}
