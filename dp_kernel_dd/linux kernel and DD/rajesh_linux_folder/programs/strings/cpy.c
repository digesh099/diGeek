#include<stdio.h>
int astrcmp(char *,char *);
int main()
{
	char str[10], str1[10], result;
	int i = 0;
	printf("enter two strings\n");
	gets(str);
	gets(str1);

	result = astrcmp(str,str1);
	if (result == 0)
	puts("both strings are same");
	else
	puts("entered strings are not equal");
	return 0;
}
int  astrcmp(char *str,char *str1)
{
	while(*str==*str1)
	{
	  if(*str=='\0'||*str1=='\0')
	  break;
	  str++;
	  str1++;
	}
	

}
	
	
