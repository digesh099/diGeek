#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
int fd[2];
int ret,s1,s2;
main()
{
	pipe(fd);
	ret=fork();
	if(ret==0)
	{
		close(1);
		close(fd[0]);
		s1=dup(fd[1]);
		execl("/bin/ls","ls","-l",NULL);
	}
	else
	{
		close(0);
		close(fd[1]);
		s2=dup(fd[0]);
		close(fd[0]);
		execl("/bin/sort","sort",NULL);
	}
}
