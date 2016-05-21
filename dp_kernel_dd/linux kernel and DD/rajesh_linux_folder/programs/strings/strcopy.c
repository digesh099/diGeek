#include<stdio.h>
main()
{
	int i=0;
	char s1[10],s2[10];
	printf("enter the first string\n");
	gets(s1);
	printf("enter the second string\n");
	gets(s2);
	while(s1[i]!=NULL)
	{
	  s2[i] = s1[i];
	  i++;
	}
	printf("after copy the string2 = %s",s2);
}
