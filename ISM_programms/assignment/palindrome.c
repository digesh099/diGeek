#include<stdio.h>
main()
{
	int i,j=0,k,rev=0,b;
	char a[50];
	printf("enter the string : ");
	gets(a);
	for(i=0;a[i]!='\0';i++)
	j=j*10+(a[i]-48);
	k=j;
	printf("\n%d",j);
	while(k)
		{
			b=k%10;
			rev=rev*10+b;
			k=k/10;
		}
		printf("\n%d",rev);
		if(rev==j)
		printf("\n the string is palindrome");
		else
		printf("\n the string is not palindrome");
}
