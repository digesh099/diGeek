#include "strng.h"


void str_cat(char str1[], char str2[])
{
	int i=0, j;
	while(str1[i] != '\0')
	{
	  i++;
	}  
	for(j=0; str2[j] != '\0';j++)
	str1[i+j] = str2[j];
	str1[i+j] = '\0';
	puts(str1);
}

	

