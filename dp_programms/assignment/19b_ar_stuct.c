#include<stdio.h>
struct bank
{
	char name[20];
	int ac_no;
	float bal;
}a={"digesh",342516,1025.50};


	
main()
{
	struct bank *p;
	p=&a;
	printf("\n%s\t%d\t%f\n",(*p).name,(*p).ac_no,(*p).bal);
	printf("%s\t%d\t%f\n",p->name,p->ac_no,p->bal);
}
