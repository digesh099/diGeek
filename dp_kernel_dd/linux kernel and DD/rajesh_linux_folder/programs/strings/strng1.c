#include "strng.h"


void str_cpy(char dest[], char src[])
{
	int i=0;
	while(src[i]!='\0')
	{
	  dest[i] = src[i];
	  i++;
	}
	dest[i] = '\0';
	puts(dest);
}

	

