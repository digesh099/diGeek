#include<stdio.h>

struct student
{
	char name[20];
	int rollno;
	int marks[6];
	int total;
	char grade;
};

void display(struct student arr);
void calculate(struct student arr[]);
void sort(struct student arr[]);

int main(void)
{
	int N =4;
	struct student stu[N],temp;
	int i, j;
	for(i = 0; i < N; i++)
	{
	  printf("enter the name\n");
	  scanf("%s",stu[i].name);
	  printf("enter the roll no\n");
	  scanf("%d",&stu[i].rollno);
	  stu[i].total = 0;
	  printf("enter the marks in 6 subjects\n");
	  for(j = 0; j < 6; j++)
	  scanf("%d",&stu[i].marks[j]);
	}
	calculate(stu);
	sort(stu);
	for(i = 0; i <N; i++)
		display(stu[i]);
		return 0;
}

void calculate(struct student stu[])
{
	int i,j;
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j <6; j++)
		   stu[i].total = stu[i].total + stu[i].marks[j];
		if(stu[i].total > 500)
		   stu[i].grade = 'A';
		else if(stu[i].total > 400)
		   stu[i].grade = 'B';
		else if(stu[i].total > 250)
		   stu[i].grade = 'C';
		else
		   stu[i].grade = 'D';
	}
}

void sort(struct student stu[])
{
	int i, j;
	struct student temp;
	for(i = 0; i < 3; i++ )
	for(j = i+1; j < 4; j++)
	  if(stu[i].total < stu[j].total)
	  {
		temp = stu[i];
		stu[i] = stu[j];
		stu[j] = temp;
	}
}

void display(struct student stu)
{
	printf("roll no - %d\t",stu.rollno);
	printf("name    - %s\t",stu.name);
	printf("total   - %d\t",stu.total);
	printf("grade   - %c\n\n",stu.grade);


}



