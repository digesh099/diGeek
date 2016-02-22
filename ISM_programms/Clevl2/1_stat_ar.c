#include<stdio.h>
main()
{
	int a[20],i,b;
	printf("enter the size of array\n");
	scanf("%d",&b);
	printf("enter the array elems.\n");
	for(i=0;i<b;i++)
		scanf("%d",&a[i]);
	for(i=0;i<b;i++)
		printf("\n%d",a[i]);
}
	
