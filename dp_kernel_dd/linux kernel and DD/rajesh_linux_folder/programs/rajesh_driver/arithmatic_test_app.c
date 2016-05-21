/* application can be implemented to perform different operation on kernel */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdlib.h>

int main()
{
	int fd, i; 
	char my_buf[2000];
	unsigned int value = 50;
	char c;
	
	for(i = 0; i < 2000; i++)
	my_buf[i] = '*';

	printf("[%d] - opening device grajesh_cdrv\n",getpid());
	fd = open("/dev/grajesh_cdrv",O_RDWR);
	
	if(fd<0)
	{
		printf("device could not be opened\n");
		return 1;
	}

	printf("device opened with id - [%d]", fd);

	write(fd, my_buf, 2000);
	read(fd, my_buf,50);
	
	printf("i read this from the device\n%s\n"my_buf);

	ioctl(fd, ADD, &value);
	if(ioctl(fd, ADD, &value) < 0)
		printf("ioctl failed to open\n");
	  
	read(fd, my_buf,50);
	printf("the result present in the buffer is %s\n", my_buf);
	close(fd);
	exit(0);
}



	

	
