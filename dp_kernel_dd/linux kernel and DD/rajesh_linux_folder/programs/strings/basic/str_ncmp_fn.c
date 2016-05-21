#include<stdio.h>
#include<string.h>

int main(void)
{
	char str1[15] = "rajesh g";
	char str2[15] = "rajsh g";
	if(strncmp(str1,str2,5) == 0)
	printf("same\n");
	else
	printf("different\n");
}
