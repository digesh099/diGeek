#include<stdio.h>
int fd[2];
main()
{
	char buf[8];
	pipe(fd);
	printf("%d\t%d\n",fd[0],fd[1]);
	write(fd[1],"digesh",6);
	read(fd[0],buf,6);
	printf("%s",buf);
	

}
