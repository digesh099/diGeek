#include<stdio.h>
int fact(int);
main()
{
	int a,factorial;
	printf("enter the no. : ");
	scanf("%d",&a);
	factorial=fact(a);
	printf("\nthe factorial of %d is %d\n ",a,factorial);
}
int fact(int a)
{
	int x;
	if(a==1 || a==0)
	return 1;
	x=a*fact(a-1);
	return x;
}
