#include<stdio.h>

struct student 
{
	char name[20];
	int rollno;
	int submarks[4];
};

int main(void)
{
	struct student stu[5];
	int i,j;
	for(i = 0; i < 5; i++)
	{
		printf("enter the student %d  details\n",i+1);
		scanf("%s %d",stu[i].name,&stu[i].rollno);
		for(j = 0; j < 4; j++)
		{
		  printf("enter the %d subject marks :\n",j+1);
		  scanf("%d",&stu[i].submarks[j]);
		}
	}
	for(i = 0; i < 5; i++)
	{
		printf("data of student %d is \n",i+1);
		printf("name  :%s rollno :%d marks :",stu[i].name,stu[i].rollno);
		for(j = 0; j < 4; j++)
	
			printf("%d ",stu[i].submarks[j]);
		printf("\n");
	}
}
