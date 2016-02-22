#include<stdio.h>
main()
{
	int a,b,c=0,d,i,j,e;
	printf("enter the range :");
	scanf("%d%d",&a,&b);
	e=a;
	printf("\nthe prime nos are:\n ");
	for(i=e;i<=b;i++,a++)
	{
		 for(j=1;j<=a;j++)
		{
		d=a%j;
		if(d==0)
		c=c+1;
		}
		if(c==2)
		
		printf(" %d ",a);
		
	c=0;	
	}
}
