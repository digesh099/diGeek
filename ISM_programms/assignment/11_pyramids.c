#include<stdio.h>
main()
{
	int a,b,i,j;
	printf("enter which operation :\n");
	printf("1.number pyramid\n2.floyd's triangle\n3.asteriks\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1: printf("enter how many rows\n");
			scanf("%d",&b);
			for(i=1;i<=b;i++)
			{
				for(j=b-i;j>=1;j--)
				printf(" ");
				for(j=1;j<=i;j++)
				printf("%d",j);
				for(j=i-1;j>=1;j--)
				printf("%d",j);
			printf("\n");
			}
			break;
		case 2: printf("enter how many rows\n");
			scanf("%d",&b);
			int x=1;
			for(i=1;i<=b;i++)
				{for(j=1;j<=i;j++)
				printf(" %d ",x++);
			printf("\n");
					}
			break;
		case 3: printf("enter how many rows\n");
			scanf("%d",&b);
			for(i=1;i<=b;i++)
			{for(j=b-i;j>=1;j--)
			printf(" ");
			for(j=1;j<2*i;j++)
			printf("*");
			printf("\n");}
			break;
		default :printf("\nenter no is wrong\n");
	}
}
