#include<stdio.h>
main()
{
	char *str;
	int a;
	printf("hw many elements : ");
	scanf("%d",&a);
	str=(char*)malloc(a);
	scanf("%s",str);
	str=(char*)realloc(str,15);
	strcat(str,"how are yu");
	printf("%d\t%s",str,str);
	free(str);
	printf("%d\t%s",str,str);
}
