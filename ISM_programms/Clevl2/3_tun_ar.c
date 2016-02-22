#include<stdio.h>
#include "extn.c"
extern int n;
main()
{
	int a[n],i;
	printf("enter the array elems:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("entered elems are\n");
	for(i=0;i<n;i++)
		printf("%d",a[i]);
}
