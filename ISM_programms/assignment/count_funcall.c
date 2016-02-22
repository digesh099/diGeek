#include<stdio.h>
int sum();
static int a;
main()
{
	sum();
	sum();
	sum();
	printf(" \nno of time fun call is : %d\n",a);
	
}
int sum()
{
	static int b;
	int x;
	x=a++ + b++;
	//a++,b++;
	
	printf("\n%d",x);
}
	
	
