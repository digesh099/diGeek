#include<stdio.h>
main()
{
	char vehicle[10];
	char name[10];
	int no;
	printf("enter the type of vehicle\n");
	scanf("%s",&vehicle);
	printf("enter the train name\n");
	scanf("%s",&name);
	printf("enter no\n");
	scanf("%d",&no);

	printf("the vehicle is %s\n",vehicle);
	printf("the train is %s\n",name);
	printf("vehicle no is %d",no);
}
