#include<stdio.h>
struct student
{
	char name[20];
	int rollno;
	int marks;
};


void display(struct student );
struct student change(struct student);

int main(void)
{
	struct student stu1 = { "rajesh", 26, 78 };
	struct student stu2 = { "sathish",48, 85 };
	stu1 = change(stu1);
	stu2 = change(stu2);
		
	display(stu1);
	display(stu2);
	
	return 0;
}

struct  student change(struct student stu)
{
	stu.marks = stu.marks + 5;
	stu.rollno = stu.rollno - 10;
	return stu;
}

void display(struct student stu)
{
	printf("name    - %s\t",stu.name);
	printf("rollno  - %d\t",stu.rollno);
	printf("marks   - %d\n",stu.marks);
}
