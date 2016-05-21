/* this program implements the string concatination */

#include<stdio.h>
#include<stdlib.h>

char * str_concat(char str1[], char str2[]);

int main(void)
{
	char str[40], str1[20];
	printf("enter the first string \n");
	scanf("%s", &str);
	printf("enter the second string\n");
	scanf("%s",&str1);
	
	str_concat(str,str1);
	
	printf("after concatination the resultant string is %s\n",str);
}

char * str_concat(char str[], char str1[])
{
	int i, j;
	while(str[i] != '\0')
	{
		i++;
	}
	for(j = 0; str1[j] != '\0'; j++)
	{
		str[i + j] = str1[j];
	}
	str[i +j] = '\0';
	return str;
}
