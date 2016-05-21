#include<stdio.h>
void str_len(char *);
main()
{
	
	char *str ="rajeshgandla";
	str_len(str);

}
void str_len(char *p)
{
	int i=0;
	do
	{
	  i++;
	}
	while(*(p+i)!='\0');
	printf("%d",i);
}
