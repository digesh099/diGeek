#include<stdio.h>
void func(char , void (*fp)(float));
void func1(float);
int main()
{
	printf("function main() called \n");
	func('a', func1);
	return 0;
}
void func(char b, void (*fp)(float))
{
	printf("function func() is called \n");
	printf("char is %c\n",b);
	(*fp)(5.6);
}

void func1(float f)
{
	printf("function func1() is called \n");
	printf("float  is %f\n",f);
}

