#include<stdio.h>
main()
{
	char str[10];
	int i,j,a,k;
	printf("enter the string : ");
	gets(str);
	a=strlen(str);
//	printf("\n%d",a);
	for(i=0;i<a;i++)
	{	
		for(j=i+1;j<a-1;j++)
		{
			
			if(str[i]==str[j])
			str[j]='\0';
		
		}
	}
	for(k=0;k<a-1;k++)
	printf("%c",str[k]);
	
}
