#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
void fun(int signo)
{
	printf("In Handler fun %d\n",signo);
}
int no;
main()
{
	signal(2,fun);
	printf("\nenter no.");
	scanf("%d",&no);
}

