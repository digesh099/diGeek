#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
char buf[3];int fd1[2],fd2[2],ret;
main()
{
	
	pipe(fd1);
	pipe(fd2);
	ret=fork();
	if(ret==0)
	{
	write(fd1[1],"ism",3);
//	close(fd1[0]);
	write(fd2[1],"aaa",3);
//	close(fd2[0]);
	}
	else
	{
		read(fd1[0],buf,3);
//		close(fd1[1]);
		printf("\n%s\n",buf);
		read(fd2[0],buf,3);
//		close(fd2[1]);
		printf("%s\n",buf);
	}
}
