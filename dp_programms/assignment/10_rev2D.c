#include<stdio.h>
main()
{
	int a[5][5],b[5][5],r,c,i,j,x,y,m,n;
	printf("enter the raws & column : \n");
	scanf("%d%d",&r,&c);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&a[i][j]);
	m=--i;n=--j;
	for(x=0,i=m;x<r;x++,i--)
		for(y=0,j=n;y<c;y++,j--)
			printf("b[%d][%d]=a[%d][%d]",x,y,i,j);
			b[x][y]=a[i][j];
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			printf("%d",b[i][j]);
}
