#include<stdio.h>
void sensex(struct market *q);
struct market
{
	char name[20];
	int list_no;
	float share;
	}a={"Reliance Cap",7,1255.90};

main()
{
	struct market *p;
	p=&a;
	sensex(p);
}
void sensex(struct market *q)
{
	printf("%s\t%d\t%f\n",q->name,q->list_no,q->share);
}
	
