#include<stdio.h>
main()
{
	int i,b;
	float avg,sum=0,*p,a[10];
	p=a;
	printf("hw many nos : \n");
	scanf("%d",&b);
	for(i=0;i<b;i++)
		{printf("enter %d no. :\n",i);
		scanf("%f",(p+i));
		sum=sum + *(p+i);
		printf("%f\n",sum);
		}
	printf("%f",sum);
	avg=sum/b;
	printf("\nthe avg of nos is : %f\n",avg);
}
	
