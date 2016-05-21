#include<stdio.h>

struct book
{
	char author[20];
	int page;
	float price;
};

struct student
{
	int rno;
	char name[20];
	float m;
	struct book *bk;
}s1, s2, s3;

//struct book b1 = {"aaaa", 12, 15};

//s1.bk = &b1;

main()

{	
	
	
	s1.bk=malloc(sizeof(struct book));
	
	printf("enter the first student details\n");
	scanf("%d %s%f", &s1.rno, s1.name, &s1.m);
	printf("%d %s%f\n", s1.rno, s1.name, s1.m);

	printf("enter the second  student details\n");
	scanf("%d %s%f", &s2.rno, s2.name, &s2.m);
	printf("%d %s%f\n", s2.rno, s2.name, s2.m);
	
	printf("enter the third student details\n");
	scanf("%d %s%f", &s3.rno, s3.name, &s3.m);
	printf("%d %s%f\n", s3.rno, s3.name, s3.m);
	
	printf(" book details\n");
	scanf(" %s%d%f",s1.bk->author,&s1.bk->page,&s1.bk->price);
//	printf(" %s%d%f",s1.bk.author,s1.bk.page,s1.bk.price);
	printf(" %s %d %f", s1.bk->author, s1.bk->page, s1.bk->price);

}
