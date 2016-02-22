#include<stdio.h>
main()
{
	int *p,n,i;
	printf("enter the size of the array\n");
	scanf("%d",&n);
	p=(int *)malloc(sizeof(int)*n);
	printf("enter the array elems.\n");
	for(i=0;i<n;i++)
		scanf("%d",(p+i));
	printf("entered array is\n");
	for(i=0;i<n;i++)
		printf("%d\n",*(p+i));
}
