#include<stdio.h>
void fr(int);
void whil(int);
void dw(int);
main()
{
	int n,count=0;
	char ch;
	
	printf("enter the n value\n");
	scanf("%d", &n);
	

	printf("f:forloop\n w:while\n d:dowhile\n");
	
	while(1)
	{
	printf("enter the choice\n");
	scanf(" %c", &ch);
	switch(ch)
	{
	  case 'f':fr(n);
		   break;
	  case 'w':whil(n);
		   break;
	  case 'd':dw(n);
			
		   break;
	  default :puts("invalid\n");
	}
	}
}
void fr(int x)
{
	int i,count=0;
	for(i=0;i<=x;i++)
	{
	count=count+i;
	}
	printf("%d\n",count);
}
void whil(int x)
{
	int i=0,count=0;
	while(i<=x)
	{
	  count=count+i;
	  i++;
	}
	  printf("%d\n",count);
}
void dw(int x)
{
	int i=0,count=0;
	do
	{
	  
	  count=count+i;
	  i++;
	}while(i<=x);
	printf("%d",count);
}




