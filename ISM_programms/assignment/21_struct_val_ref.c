#include<stdio.h>
void fun(struct student b);
	struct student
	{
		char name[10];
		int id_no;
		float marks;
	}a={"digesh",99,90.78};
	main()
	{
	
fun(a);
}
void fun(struct b)
{
	printf("\n%s\t%d\t%f\n",b.name,b.id_no,b.marks);
}
