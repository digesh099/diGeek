#include<stdio.h>
#include<signal.h>
void fun(int signo)
{
	printf("in handler fun : %d",signo);
}
main()
{	int a;
	signal(8,fun);
	printf("entr the no\n");
	scanf("%d",a);
	printf("entered no is %d",a);
}
