#include<stdio.h>
main()
{
	int n,c,array[100];
	float sum = 0;
	printf("enter the value of n");
	scanf("%d",&n);
	for(c=0;c<n;c++)
	{
		printf("enter the values of array");
		scanf("%d",&array[c]);
		sum=sum+array[c];
	}
	printf("sum=%f   avg = %f\n",sum, (sum/c));
	return 0;
}


