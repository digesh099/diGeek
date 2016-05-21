#include<stdio.h>
main()
{
	int str[20],sub[20],*p;
	printf("enter the main string :\n");
	gets(str);
	printf("enter the sub string :\n");
	gets(sub);
	p=strstr(str,sub);
	if(p==NULL)
	printf("string not found\n");
	else
	printf("\nsub string found at %d location\n",p-str);
}
	
	
