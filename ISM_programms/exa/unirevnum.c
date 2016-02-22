#include<stdio.h>
main()
{
	int a,b,i;
	printf("enter num\n");
	scanf("%d",&a);


	
	
	
	while(a!=0)
		{
			b=a%10;
			printf("%d",b);
			a=a/10;
		
		}
}
