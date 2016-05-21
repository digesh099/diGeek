#include<stdio.h>


struct st
{
	int rno1;
	int rno2;
	char n1;
	char n2;
	float m1;
	float m2;
}s1;


struct st1
{
	int r1;
	char name1;
	float mrk1;
	char name2;
	int r2;
	float mrk2;
}s2;

struct st3
{
	int rn1;
	float mm1;
	int rn2;
	char nme1;
	char nme2;
	float mm2;
}s3;


struct st4
{
	int rnm1;
	char nmm1;
	float mn1;
	float mn2;
	int rnm2;
	char nmm2;
}s4;


int main(void)
{
	printf("%d\n", sizeof(s1));
	printf("%d\n", sizeof(s2));
	printf("%d\n", sizeof(s3));
	printf("%d\n", sizeof(s4));

}
