#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[50];
	int i, j;
	printf("enter a string\n");
	gets(str);
	for(i = 0, j = strlen(str)-1; i <= j; i++,j--)
		if(str[i]!= str[j])
		break;
		if(i > j)
		printf("string is a palindrom\n");
		else
		printf("string is not a palindrom\n");
	return 0;
}

