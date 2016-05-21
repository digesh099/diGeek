#include<stdio.h>

struct student
{
	char name[20];
	int rollno;
	int marks;
};

void display(struct student *);
void inc_marks(struct student *);

int main(void)
{
	struct student stu1 = { "rajesh", 12, 87 };
	struct student stu2 = { "karthik",26, 90 };
	inc_marks(&stu1);
	inc_marks(&stu2);
	display(&stu1);
	display(&stu2);
	  
	return 0;
}

void inc_marks(struct student *stptr)
{
	(stptr -> marks)++;
}

void display(struct student *stptr)
{
	printf("name     - %s\t", stptr -> name);
	printf("roll no  - %d\t", stptr -> rollno);
	printf("marks    - %d\n", stptr -> marks);
}


