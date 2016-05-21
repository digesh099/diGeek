#include<stdio.h>
main()
{
	const int a=10;
	int *p;
	p=&a;
	*p=50;
	printf("%d",a);
}
