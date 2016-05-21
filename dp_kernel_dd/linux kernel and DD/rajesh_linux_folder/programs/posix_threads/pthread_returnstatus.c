#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void * func1(void *arg1)
{
	printf("in func1\n");
	while(1)
	printf("haiiii\t");
}
void * func2(void *arg2)
{
	printf("in function2 \t");
}


main()
{
	pthread_t ptr1, ptr2;
	pthread_create(&ptr1, NULL, func1, NULL);
	pthread_create(&ptr2, NULL, func2, NULL);
	
	getchar();
	printf("in main function\n");
}
