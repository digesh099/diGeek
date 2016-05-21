#include<stdio.h>
#include<string.h>


int main(void)
{
	char *p;
	p = strchr("multinational",'n');
	printf("%s\n",p);
	p = strrchr("multinational",'n');
	printf("%s\n",p);
}
