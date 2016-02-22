#include<stdio.h>
main()
{
	int bin[20],a,b,i=0,j;
	printf("enter the no\n");
	scanf("%d",&a);
	while(a)
	{
		b=a%2;
		bin[i++]=b;
		a=a/2;
	}
	for(j=--i;j>=0;j--)
	printf("%d",bin[j]);
	printf("\nenter the operation\n");
	printf("1.set\n2.clear\n");
	scanf("%d",&b);
	if(b==1)
	{	printf("enter bit no. :\n");
		scanf("%d",&a);
		for(j=i;j>=0;j--)
			{bin[a]=1;
			printf("%d",bin[j]);}
	}
	if(b==2)
	{	printf("enter bit no.:\n");
		scanf("%d",&a);
		for(j=i;j>=0;j--)
		{bin[a]=0;
		printf("%d",bin[j]);}
	}
	//	printf("entered no. is wrong:\n");
}
	
		
	
	
