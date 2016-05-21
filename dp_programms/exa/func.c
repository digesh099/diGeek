#include<stdio.h>
int mul(int a,int b); 
main()
{
	int a,b,s;
	printf("enter the no. : ");
	scanf("%d %d",&a,&b);
	s=mul(a,b);
	printf("\nthe ans is : %d",s);
}
int mul(int a,int b)
{
	int c;
	c=a*b;
	return c;
}
