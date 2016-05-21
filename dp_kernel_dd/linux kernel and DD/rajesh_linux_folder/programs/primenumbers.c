#include<stdio.h>
main()
{
	int i,j,n;
	int prime = 0;
	printf("enter how many prime numbers you want to print");
	scanf("%d",&n);
			printf("\n%d\n", n);
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=i;j++)
		{
			prime = 0;
			if(i%j==0)
			{
				prime = 1;
				break;
			}
		}
		if(prime == 0)
			printf("%d\n", i);
	}
	return;
}
