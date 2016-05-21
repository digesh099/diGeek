#include<stdio.h>

float add(int , float);
float sub(int , float);
float mul(int , float);
float div(int , float);

int main()
{
	int i, b;
	float a;
	float (*fp[])(int, float) = {add, sub, mul, div};
	char *operation[] = {"add", "subtract", "multiplication", "division"};

	printf("enter integer and float \n");
	scanf("%d%f",&b,&a);
	
	for(i=0;i<4;i++)
	   printf("%s: %.2f\n",operation[i],(*fp[i])(a,b));
	   return 0;
	
}

float add(int a, float b)
{
	return a+b;
}
float sub(int a, float b)
{
	return a-b;
}
float mul(int a, float b)
{
	return a*b;
}
float div(int a, float b)
{
	return b/a;
}


