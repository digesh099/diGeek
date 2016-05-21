#include<stdio.h>

#define RAJESH 100;
int a = RAJESH;

struct stdd
{
	int rno;
	char name[10];
};
struct stdd s1;
s1 = {11,"666"};

//s1 = { 12, "1111"};
//s1.rno = 10;
//s1.name = "aaaa";

main()
{
	printf("enter the student details\n");
//	scanf("%d %s",&s1.rno, s1.name );
	printf("%d %s",s1.rno, s1.name);
	
	//s2=&s1;
//	printf("%d %s",s2.rno, s2.name);
	
}
