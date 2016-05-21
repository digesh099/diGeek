#include<stdio.h>
main()
{
	int a[3][3],i,j;
	int (*p)[3];
	printf("enter the elements : \n");
	for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
		}
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
			printf("%d",*(a+i));
	}
}
