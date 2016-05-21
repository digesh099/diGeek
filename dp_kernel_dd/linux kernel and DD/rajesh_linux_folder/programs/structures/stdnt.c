#include<stdio.h>
struct student
{
	int rno;
	char name[20];
	float m;
}s1,s2,s3;
main()
{
	printf("enter the first student details\n");
	scanf("%d %s%f",&s1.rno,s1.name,&s1.m);
	printf("%d %s%f\n",s1.rno,s1.name,s1.m);

	printf("enter the second  student details\n");
	scanf("%d %s%f",&s2.rno,s2.name,&s2.m);
	printf("%d %s%f\n",s2.rno,s2.name,s2.m);
	
	printf("enter the third student details\n");
	scanf("%d %s%f",&s3.rno,s3.name,&s3.m);
	printf("%d %s%f\n",s3.rno,s3.name,s3.m);
}
