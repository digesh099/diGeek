#include<stdio.h>
main()
{
	struct derived
	{
		char name[20];
		long a;
	struct base
	{
		int b;
		float marks;
	}sub;
	}test={"digesh",342568,99,99.8};

	printf("\n%s\t%ld\n%d\n%f\n",test.name,test.a,test.sub.b,test.sub.marks);
}
	
