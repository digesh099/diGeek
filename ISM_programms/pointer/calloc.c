#include<stdio.h>
main()
{
	int *p,*q,i,j,x,y;
	printf("how many blocks? ");
	scanf("%d",&i);
	printf("\nhow many elements in a block");
	scanf("%d",&j);
	p=(int*)calloc(i,sizeof(int)*j);
	q=p;
//	p[1]=(int*)calloc(i,sizeof(int)*j);
	printf("\n%d\n",p);
	for(x=0;x<i;x++)
	{
		for(y=0;y<j;y++)
		{	printf("(%d,%d) @ %d\n",x,y,p);
			scanf("%d",p);
			p=p+1;
		}
	}
	for(x=0;x<i;x++)
		for(y=0;y<j;y++)
			printf("%d",*q++);
}
