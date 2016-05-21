#include<stdio.h>
main()
{
	int i=0,j=0;
	char str1[20],str2[20];
	puts("enter the first string");
	gets(str1);
	puts("enter the second string");
	gets(str2);
	puts("before concatination strings are");
	puts(str1);
	puts(str2);
	while(str1[i]!='\0')
	{
	  i++;
	}
	while(str2[j]!='\0')
	{
	  str1[i++]=str2[j++];
	}

	str1[i]='\0';
	printf("after the concatination strings are\n");
	puts(str1);
	return 0;
}


