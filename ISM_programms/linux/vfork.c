#include<stdio.h>
int ret,gv=1;
main()
{
	ret=vfork();
	if(ret==0)
	{
		gv++;
		printf("%d",gv);
		_exit(0);
	}
	else
	{
		gv++;
		printf("%d",gv);
	}
}
	
