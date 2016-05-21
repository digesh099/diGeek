#include<stdio.h>
main()
{
	int a,b,c,i=0,j,bin[10];
	printf("enter the no \n");
	scanf("%d",&a);
	while(a)
	{
		b=a%2;
		bin[i++]=b;
		a=a/2;
	}
	for(j=--i;j>=0;j--)
	printf("%d",bin[j]);
	printf("\n1.check set or clear\n2.toggle\n");
	scanf("%d",&b);
	switch(b)
	{
		case 1:printf("enter no whch u wanna check\n");
			scanf("%d",&b);
			if(bin[b]==1)
			printf("%dth bit is set\n",b);
			else
			printf("%dth bit is clear\n",b);
			break;
		case 2:printf("enter bit no. whch u wana toggle:\n");
			scanf("%d",&b);
			for(j=i;j>=0;j--)
				{if(j==b)
				bin[j]=!bin[j];
				printf("%d",bin[j]);}
			break;
		default:printf("u entered wrong no.");
	}
	
}
