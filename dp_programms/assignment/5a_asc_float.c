#include<stdio.h>
main()
{
	char a[10];
	int i,j=0,k,l;
	float b=0;
	printf("enter the string : ");
	gets(a);
	for(k=0;a[k]!='.';k++)
	j=j*10+(a[k]-48);
	for(i=k+1;a[i]!='\0';i++)
	 b=b*10+(a[i]-48);
	for(l=k+1;a[l]!='\0';l++)
	b=0.1*b;
	
		
	printf("\nthe float no is : %f",j+b);
}
	
