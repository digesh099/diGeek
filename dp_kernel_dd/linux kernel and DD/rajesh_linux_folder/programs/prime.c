#include<stdio.h>
main()
{
	int n,i=1,j,c;
	printf("enter number of terms");
	scanf("%d",&n);
	printf("prime numbers are following");
	while(i<=n)
	{
		c=0;
		for(j=1;j<=i;j++)
		{
		if(i%j==0)
		c++;
		}
		if(c==2)
		printf("%d\n",i);
		i++;
	}
	return 0;
}


