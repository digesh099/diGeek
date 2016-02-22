#include<stdio.h>
main()
{
	char a[]="125";
	int b[5],c,i,j=0,d;
	for(i=0;a[i]!='\0';i++,j++)
		b[j]=a[i]-48;
	
	c=b[0]*100+b[1]*10+b[2]*1;
	printf("enter the no whch u want to add :");
	scanf("%d",&d);
	d=d+c;
	printf("\ninteger is :%d ",d);
}
	
