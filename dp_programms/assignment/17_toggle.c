#include<stdio.h>
main(int a,char *b[])
{
	int i,j,c,word;
	char d;
	printf("%d\n",a);
	for(i=0;i<a;i++)
	printf("%s\n",b[i]);
	printf("enter the word no :\n");
	scanf("%d",&word);
	c=strlen(b[word-1]);
	for(j=0,i=(word-1);j<c;j++)
	{	
	if(isupper(b[i][j]))
		d=tolower(b[i][j]);
		else
		d=toupper(b[i][j]);
	printf("%c",d);
}
}
	
