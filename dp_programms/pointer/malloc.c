#include<stdio.h>
main()
{
	int *p;
	int i,n;
	printf("enter no of element : \n");
	scanf("%d",&n);
	p=(int *)malloc(sizeof(int)*n);
	printf("%d @ %d %d\n",p,*p,*(p+1));
	printf("total memmory allacation is %d\n",sizeof(int)*n);
	for(i=0;i<n;i++)
	{	printf("eneter %d  elem @ %d ",i,p+i);
		scanf("%d",(p+i));
	}
	for(i=0;i<n;i++)
		printf("%d",*(p+i));
}
