#include<stdio.h>
int *fun(int,int);
static int i,j;
 main()
 {
	int (*a)[5],r,c;
	printf("enter raws and cols\n");
	scanf("%d%d",&r,&c);
	a=fun(r,c);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			printf("  %d  ",*(*(a+i)+j));
}
int *fun(int r,int c)
{	
	int a[5][5],(*p)[5];
	p=a;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		scanf("%d",&a[i][j]);
	return(p);
}
		
