#include<stdio.h>
main()
{
	extern char **environ;
	int i;
	printf("In Main\n");
	putenv("PATH=/home/student/citrix/digesh/linux/my");
	for(i=0;environ[i]!=NULL;i++)
		printf("%s\n",environ[i]);
	execl("my",NULL);
//	system("ls -l");
	printf("End of main\n");
}
