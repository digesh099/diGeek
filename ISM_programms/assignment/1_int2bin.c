#include<stdio.h>
main()
{
	int a,bin[10],j,b,c=0,i=0;
	printf("enter the no :\n");
	scanf("%d",&a);
	while(a)
	{
		b=a%2;
		bin[i++]=b;
		a=a/2;
	}
	for(j=--i,b=0;j>=0;j--)
	{printf("%d",bin[j]);
	if(bin[j]==0)
	b=b+1;
	else
	c=c+1;}
	printf("\nno of 1's are:%d\nno of 0's are:%d\n",c,b);
}
