#include<stdio.h>
main()
{
	float a[50],sum=0,avg;
	int i,b;
	printf("enter the size of array\n");
	scanf("%d",&b);
	for(i=0;i<b;i++)
		{
			scanf("%f",&a[i]);
			sum=sum+a[i];
		}
		
	avg=sum/b;
	printf("the avg of array is %f",avg);	
}
	
	
