#include<stdio.h>
main()
{
	struct
	{
		int rol_no;
		float mark;
		char name[10];
	}a[10];
	int i,n;
	printf("enter no of students :\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the elements : \n");
		scanf("%d%f%s",&a[i].rol_no,&a[i].mark,&a[i].name);
	}
	for(i=0;i<n;i++)
		printf("%d%f%s",a[i].rol_no,a[i].mark,a[i].name);
}
