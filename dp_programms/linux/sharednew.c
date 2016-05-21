	#include<stdio.h>
	#include<linux/shm.h>
	#include<sys/types.h>
	int shmid;
	key_t key;
	main()
	{
		char *ptr;
		key=ftok(".",'d');
		shmid=shmget(key,100,IPC_CREAT|0777);
		printf("shmid=%d\n",shmid);
		//ptr=(char *)malloc(100);
		
		ptr=(char*)shmat(shmid,0,0);
		printf("enter the data for process 2 \n");

		scanf("%s",ptr);
		//printf("output of process 1 %s",ptr);
	}
