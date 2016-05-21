#include<stdio.h>
main()
{
	struct student
	{
		char name[10];
		int id;
		float marks;
	}*p;
	p=(struct student *)malloc(sizeof(struct student));
	printf("enter student details\n");
	scanf("%s%d%f",&p->name,&p->id,&p->marks);
	printf("%s\n%d\n%f\n",p->name,p->id,p->marks);
	free(p);
	p='\0';
}
