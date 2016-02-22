#include<stdio.h>
struct bank
{
	char name[20];
	int ac_no;
	float bal;
}a[5];


	
main()
{
	int i;
	printf("enter the detail of customers : \n");
	for(i=0;i<3;i++)
		scanf("%s%d%f",&a[i].name,&a[i].ac_no,&a[i].bal);
	
	for(i=0;i<3;i++)
		printf("\n %s\n%d\n%f\n",a[i].name,a[i].ac_no,a[i].bal);
}
