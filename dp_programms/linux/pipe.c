#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
int fd[2],ret;
char buf[3];
main()
{
	pipe(fd);
	ret=fork();
	if(ret==0)
	{
		write(fd[1],"ism",3);
		close(fd[0]);
	}
	else
	{

		read(fd[0],buf,3);
		close(fd[1]);
		printf("%s",buf);
	}

//	printf("%d\t%d\n",fd[0],fd[1]);
}
