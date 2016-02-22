#include<stdio.h>
main()
{
	float i,*j;
	j=&i;
	printf("%u",j);
	scanf("%f",&i);
	printf("\n%d\n",*j);
	}
