#include<stdio.h>
main()
{
	int i;
	for(i=0;i<=9;i++)
	{
		printf("%d",i);
		if(i==0||i==2||i==5||i==9)
		{
			printf("\n");
		}
	}
}
