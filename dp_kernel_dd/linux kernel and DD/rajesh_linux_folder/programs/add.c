#include <stdio.h>

static int r = 12;
int add(int x)
{
	static int rrrrr = 10;
	return rrrrr;
}

main()
{
	int a =	10;
	int b = 43;
	printf("add = %d\n", (a+b));
	b = add(4);
	 printf("add111 = %d\n", b);
	 printf("ad = %d\n", r);

}
