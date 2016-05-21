#include<stdio.h>
#define N 5

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

int maint(void)
{
	struct student stu[N],temp;
	int i, j;
	for(i = 0; i < N; i++)
	{
		printf("enter a name  :");
		scanf("%s",stu[i].name);
		printf("enter a rollnumber  :");
		scanf("%d", stu[i].rollno);
		stu[i].total = 0;
		printf("enter the marks in 6 subjects  :");
		for(j = 0; j < 6; j++)
			scanf();
