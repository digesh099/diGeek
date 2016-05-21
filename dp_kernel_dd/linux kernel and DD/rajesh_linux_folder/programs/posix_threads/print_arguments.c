#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int global = 5;

void * func1(void *arg)
{
	printf("in function1\n");
	printf("value of a = %d\n",*(int *)arg);	
	global = 10;
}


void * func2(void *arg1)
{
	printf("in function2\n");
	printf("value of b = %d\n",*(int *)arg1);
	printf("value of global = %d\n", global);
	global = 20;
}

main()
{
	pthread_t ptr1, ptr2;
	int a, b;
	printf("enter the a and b values\n");
	scanf("%d%d",&a,&b);

	pthread_create(&ptr1, NULL, func1,(void *) &a);
	pthread_join(ptr1,NULL);
	pthread_create(&ptr2, NULL, func2, (void *)&b);
	pthread_join(ptr2,NULL);


	//getchar();
	printf("in main function \n");
	printf("value of global = %d\n", global);
}

