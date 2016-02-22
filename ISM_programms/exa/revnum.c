#include<stdio.h>
main()
{
	int a,b,c,d;
	scanf("%d",&a);
	b=(a%100);
	c=b%10;
	d=(c*100)+((b/10)*10)+(a/100);
	printf("the reverse num is %d \n",d);
}
