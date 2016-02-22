#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#define fname "/home/student/citrix/digesh/linux/fifo"
char buf[20];
main()
{
	int pid;
	mkfifo(fname,0777);
	pid=open(fname,O_WRONLY);
	printf("pid %d\n",pid);
	printf("enter the string\n");
	scanf("%s",buf);
	write(pid,buf,sizeof(buf));
	close(pid);
}
