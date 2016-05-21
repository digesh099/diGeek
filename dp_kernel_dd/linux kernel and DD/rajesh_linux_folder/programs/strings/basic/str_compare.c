/* this prigram implements the string comparision */

#include<stdio.h>

int str_compare(char str1[], char str2[]);

int main(void)
{
	char str1[50], str2[50];
	int x;
	printf("enter the first string\n");
	scanf("%s",&str1);
	printf("enter the second string \n");
	scanf("%s",&str2);
	x = str_compare(str1, str2);
	printf("difference between two strings %d\n",x);
	if(x == 0)
		printf("the two strings are equal\n");
	else
		printf("the two strings are not equal\n");
}

int str_compare(char str1[], char str2[])
{
	int i;
	for(i = 0; str1[i] == str2[i]; i++)
		
		if(str1[i] == '\0')
		return 0;
		
	return(str1[i]-str2[i]);

}
