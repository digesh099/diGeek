#include<stdio.h>
#include<string.h>

int main(void)
{

	char str[50];
	int len;
	printf("enter a string\n");
	gets(str);
	for(len = strlen(str)-1; len >= 0; len--)
	 printf("%c",str[len]);
	printf("\n");
	return 0;
}
