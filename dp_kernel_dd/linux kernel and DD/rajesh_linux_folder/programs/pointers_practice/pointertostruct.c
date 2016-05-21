#include<stdio.h>

struct student
{
	int rno;
	char name[20];
	float marks;
};
struct student * student_details(struct student *);

int main()
{
	struct student  *ret;
	struct student st;
	struct student * (*fp)(struct student *);
	fp  = student_details;
	ret = fp(&st);
	printf("%d %s %f\n",ret -> rno, ret -> name, ret ->marks);	
	return 0;
}


struct student * student_details(struct student *fp)
{	
	printf("enter the student details\n");
	scanf("%d %s %f",&fp ->rno, fp->name, &fp->marks);
	return fp;
}
