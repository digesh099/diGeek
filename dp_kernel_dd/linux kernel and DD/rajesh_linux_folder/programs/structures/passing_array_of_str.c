#include<stdio.h>

struct student
{
	char name[20];
	int rollno;
	int marks;
};

void display(struct student);
void dec_marks(struct student stuarr[]);	

int main(void)
{
	int i;
	struct student stuarr[] ={
					 { "rajesh", 12, 98},
					 { "karthik",14,99 },
					 { "kumar", 16, 100}
				 };
	dec_marks(stuarr);
	for(i = 0; i < 3; i++)
		display(stuarr[i]);
	return 0;
}

void dec_marks(struct student stuarr[])
{
	int i;
	for(i = 0; i < 3; i++)
	stuarr[i].marks = stuarr[i].marks -10;
}
void display(struct student stu)
{
	printf("name    - %s\t",stu.name);
	printf("rollno  - %d\t",stu.rollno);
	printf("marks   - %d\n",stu.marks);
}
