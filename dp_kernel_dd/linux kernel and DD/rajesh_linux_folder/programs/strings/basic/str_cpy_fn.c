#include<stdio.h>
#include<string.h>

int main(void)
{
	char str1[10];
	strncpy(str1, "rajesh g",6);
	str1[7] = '\0';
	printf("%s\n", str1);
	strncpy(str1,"gandla",8);
	printf("%s\n",str1);
	return 0;
}

