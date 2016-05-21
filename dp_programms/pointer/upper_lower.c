#include<stdio.h>
#include<ctype.h>
main()
{
	char *str[3]={"diGesH","NikHiL","dHaRaV"};
	char a;
	int i,j;
	printf("the given strings are:\n ");
	for(i=0;i<3;i++)
{
		//	for(j=0;str[i]!='\0';j++)
		
				printf("%s",str[i]);
		
			printf("\n");
}
	printf("the toggled strings are: \n");
	for(i=0;i<3;i++)
	{
			for(j=0;str[i][j]!='\0';j++)
		{
				if(isupper(str[i][j]))
				{
				a=tolower(str[i][j]);
				}
				else
			      {
				     a=toupper(str[i][j]);
			      }
			printf("%c",a);
				
		u}
		printf("\n");
}
}
			
	
	
	
