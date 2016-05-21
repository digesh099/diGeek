#include<stdio.h>
#include<string.h>

int main(void)
{
	char str1[15] = "rajesh ";
	//str1[7] = ' ';
	strncat(str1, "gandlaraj",6);
	printf("%s\n", str1);
	return 0;
}
