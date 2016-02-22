#include<stdio.h>
main()
{
	int a,b,c;
	scanf("%d",&a);
	b=a;
	while(a!=1)
	{
	b=b*(a-1);
	a--;
	}
	printf("the factorial num is %d\n",b);
}
