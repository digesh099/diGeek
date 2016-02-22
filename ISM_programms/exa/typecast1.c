#include<stdio.h>
main()
{
	int m1,m2,m3,tot;
	float avg;
	__fpurge(stdin);
	scanf("%d %d %d",&m1,&m2,&m3);
	tot=m1+m2+m3;
	avg=tot/3;
	printf("%f",avg);
}
