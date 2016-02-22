#include<stdio.h>
#include<sys/types.h>
#include<linux/ipc.h>
key_t key;
int mid;
struct msg
{
	long int mtype;
	char data[20];
}obj1,obj2;
main()
{
	int mid,ret;
	key=ftok(".",'a');
	mid=msgget(key,IPC_CREAT|0777);
	printf("%d",mid);
	ret=fork();
	if(ret==0)
	{
		obj1.mtype=1;
		obj1.data="ism";
		//strcpy(obj1.data,"ism");
		msgsnd(mid,&obj1,sizeof(obj1),0);
	}
	else
	{
		msgrcv(mid,&obj2,sizeof(obj2),1,0);
		printf("%s",obj2.data);
	}
} 
