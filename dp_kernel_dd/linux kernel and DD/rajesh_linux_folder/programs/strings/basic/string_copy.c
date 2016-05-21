/* this is the program to implement the string copy */

#include<stdio.h>
#include<stdlib.h>

void str_copy(char str1[], char str2[]);

int main(void)
{
	char str1[50], str2[50];
	printf("enter the source string to copy \n");
	gets(str1);
	str_copy(str2, str1);

}

void str_copy(char str2[], char str1[])
{
	int i = 0;
	while(str1[i] != '\0')
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	printf("after copying the string the destination string is = %s\n",str2);
}
