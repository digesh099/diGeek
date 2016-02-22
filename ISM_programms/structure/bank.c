#include<stdio.h>
main()
{
	struct bank
	{
		int ac_no;
		float bal;
		char name[10];
	}a={324152,4567.9,"digesh"},b={324152,658.7,"nikhil"};
	printf("%d\t%f\t%s\n",a.ac_no,a.bal,a.name);

}
