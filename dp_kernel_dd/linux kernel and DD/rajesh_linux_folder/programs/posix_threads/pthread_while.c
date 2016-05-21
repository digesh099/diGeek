#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void * first_function(void *arg)
{
	while(1)
	printf("in calling function\n");
}

main()
{
	pthread_t ptr;
	
	pthread_create(&ptr, NULL, first_function, NULL );
	getchar();
	
	printf("in main function\n");
}
