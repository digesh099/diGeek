#include<stdio.h>
void aaa(int *);
main()
{
	int a=5;
	int *ptr=0x1000;
	
	aaa(ptr);
	printf("in main function\n");
}
void aaa(int *p)
{
	printf("%d\n",*p);
}
