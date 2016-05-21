#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#define fname "/home/student/citrix/digesh/linux/fifo"

char buf[20];
int pid;
main()
{
	pid=open(fname,O_RDONLY);
	printf("%d in read\n",pid);
	read(pid,buf,sizeof(buf));
	printf("reading from named %s\n",buf);
	close(pid);
}
