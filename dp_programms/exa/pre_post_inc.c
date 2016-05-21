#include<stdio.h>
main()
{
	int a=10,b=15;
	a=a++ + ++b;
	b=++a + b++;
	printf("%d %d",a,b);
}
