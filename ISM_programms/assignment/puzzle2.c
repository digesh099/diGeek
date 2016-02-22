#include<stdio.h>
main()
{
	int a;
	char b[100];
	printf("enter the string ");
	gets(b);
	a=strlen(b);
	printf("\nthe last character is : %c",b[a-1]);
}
