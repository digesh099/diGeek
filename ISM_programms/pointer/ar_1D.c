#include<stdio.h>
main()
{
	int a[3],i;
	printf("enterthe elements os array\n");
	for(i=0;i<3;i++)
		scanf("%d",a+i);
	for(i=0;i<3;i++)
		printf("%d",*(a+i));


}
