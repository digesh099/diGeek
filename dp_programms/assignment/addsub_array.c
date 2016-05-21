#include<stdio.h>
main()
{
	int a[2][2],b[2][2],i,j,k,r,c,sum=0,m;
	printf("enter the raw and column\n");
	scanf("%d%d",&r,&c);
	printf("enter the elements of array\n");
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
			printf("%d\t",a[i][j]);
			printf("\n");
		}

	printf("\nchoose the operation\n");
	printf("1.add\n2.sub\n3.mul\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1: for(j=0;j<r;j++)
			 for(k=0;k<c;k++)
			 {
				 printf("%d\t",a[j][k]+a[j][k]);
				 printf("\n");
			 }
			 break;
		case 2: for(j=0;j<r;j++)
			 {
			 for(k=0;k<c;k++)
			 {
				 printf("%d\t",a[j][k]-a[j][k]);
				 printf("\n");
			 }
			 }
			 break;
		case 3 : for(j=0;j<r;j++)
			  {
				 for(k=0;k<c;k++)
			  	  {
					 for(m=0;m<c;m++)
				 	 {
						 sum=a[j][m]*a[m][k]+sum;
					 }
				  	b[j][k]=sum;
					sum=0;
				  }
				  
		       	  }
			  for(j=0;j<r;j++)
			 {    for(k=0;k<c;k++)
			     {
				     printf("%d\t",b[j][k]);
				}
				printf("\n");
	     		}
			  
			 
	}
}
			  
				  
				 
		
