#include<stdio.h>

struct student 
{
	char name[20];
	int rollno;
	int marks;
};

void display(struct student *);
struct student *func(struct student *, struct student *);

int main(void)
{
	struct student *stuptr;
	struct student stu1 = { "rajesh", 26 ,78 }, stu2 = { "karthik", 48, 90};
	
	stuptr = func(&stu1, &stu2);
	display(stuptr);
	return 0;
}

struct student *func(struct student *p1, struct student *p2)
{
	if(p1 -> marks > p2 -> marks)
		return p1;
	else
		return p2;
}

void display(struct student *stu)
{
	printf("name    - %s\t",stu -> name);
	printf("rollno  - %d\t",stu -> rollno);
	printf("marks   - %d\n",stu -> marks);
}
