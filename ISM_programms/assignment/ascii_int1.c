#include<stdio.h>
main()
{
	char a[10];
	int b,c=0,i;
	gets(a);
	b=strlen(a)-1;
	for(i=0;i<=b;i++)
		c=c*10+(a[i]-48);
		
		printf("\n integer no is %d :",c);
}
	
