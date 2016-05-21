#include<stdio.h>
main()
{
	int a[10][10],i,j,r,c,x,y;
	printf("enter size of array\n");
	scanf("%d%d",&r,&c);
	for(i=0;i<r;i++)
		{for(j=0;j<c;j++)
		{printf("enter [%d][%d] elem.:\n",i,j);
		scanf("%d",&a[i][j]);}}
	x=y=a[0][0];
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{if(x<a[i][j])
		x=a[i][j];
		if(y>a[i][j])
		y=a[i][j];}
	printf("largest No is:%d\nsmallest No is:%d\n",x,y);
}
