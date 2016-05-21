#include<stdio.h>
struct dob
{
	int day;
	char *m;
	int year;
};

struct st
{
	int rno;
	char *n;
	float mrks;
	struct dob *d;
};
main()
{
	struct st *ptr;
	ptr = malloc(sizeof(struct st));
	printf("enter the student details\n");
	ptr->n = malloc(25);
	scanf("%d %s %f",&ptr->rno,ptr->n,&ptr->mrks);
	printf("enter dob details");
	ptr->d=malloc(sizeof(struct dob));
	ptr->d->m=malloc(25);
	scanf("%d %s %d",&ptr->d->day,ptr->d->m,&ptr->d->year);
	printf("%d %s%f\n",ptr->rno,ptr->n,ptr->mrks);
	printf("%d %s %d\n",ptr->d->day,ptr->d->m,ptr->d->year);
}


	
	
	
