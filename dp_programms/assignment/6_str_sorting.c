#include<stdio.h>
main()
{
	char a[20],*p,*q,i;
	int d=0,j;
	printf("enter string\n");
	gets(a);
	p=a;
	q=(char*)malloc(strlen(a));
	for(i='a';i<='z';i++)
		for(j=0;a[j]!='\0';j++)

