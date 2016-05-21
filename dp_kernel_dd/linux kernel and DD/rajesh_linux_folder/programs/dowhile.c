#include<stdio.h>
main()
{
	int i=1;
	printf("condition is not checked for first time\n");
	do
	{
		printf("now,condition is true and value is %d\n",i);
		i++;
	}
	while(i<10);
}
