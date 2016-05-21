#include<stdio.h>
#include<sched.h>
int fun(void *arg)
{
	printf("%d\n%d\n%d\n",*(int*)arg,getpid(),getppid());
	*(int*)arg=5;
}
main()
{
	int m=10;
	int *ptr;
	ptr=(int*)malloc(200)+200;
//	clone(fun,ptr,CLONE_PARENT,&m);
	clone(fun,ptr,CLONE_VM,&m);
	printf("%d\n",m);
	printf("%d\n%d\n%d\n",getpid(),getppid());
}
