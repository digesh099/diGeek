#include<stdio.h>
#include<stdarg.h>
void fun(int,...);
main()
{
	fun(10,1,2,3,4,5,6,7,8,9,10);
	fun(3,1,2,3);
}
void fun(int num,...)
{
	int tot=0,i;
	va_list ptr;
	int a[20];
	va_start(ptr,num);
	for(i=0;i<num;i++)
		a[i]=va_arg(ptr,int);
	for(i=0;i<num;i++)
		tot=tot+a[i];
	printf("\n%d\n",tot);
}

