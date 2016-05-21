#include<stdio.h>
#include "strng.h"
int main(void)
{
	int x;
	char src[10], des[10], strlen[15];
	char str1[10], str2[10];
	printf("the string operations are\n");
	
	printf("enter the string to find length\n");
	gets(strlen);
	x = str_len(strlen);
	printf("%d\n",x);
	
	printf("enter the source string\n");
	gets(src);
	str_cpy(des, src);

	printf("enter the first string\n");
	gets(str1);
	printf("enter the second string\n");
	gets(str2);	
	str_cat(str1, str2);
	printf("in main function\n");
}

