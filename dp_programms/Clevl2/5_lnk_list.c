#include<stdio.h>
void add(int *);
void del(int *);
void disp(int *);
void add_beg(int *);
void add_end(int *);
void add_btw(int *);
int count=0;
main()
{
	int a[5]={0},b;
	printf("enter the operation :\n");
	while(1)
	{
	printf("1.add\n2.del\n3.display\n4.exit\n");
	scanf("%d",&b);
	switch(b)
	{
		case 1: add(a);break;
		case 2: del(a);break;
		case 3: disp(a);break;
		case 4: exit(0);
	}
	}
}
void add( int *a)
{
	int b;
	while(1)
	{
	printf("1.add_beg\n2.add_end\n3.add_btw\n4.return\n");
	scanf("%d",&b);
	switch(b)
	{
		case 1:add_beg(a);break;
		case 2:add_end(a);break;
		case 3:add_btw(a);break;
		case 4:return;
	}
	}
}
void add_beg(int *a)
{
	int i,data;
	if(count==5)
	printf("\nthe array is full\n");
	printf("\nenter the data\n");
	scanf("%d",&data);
	for(i=count;i>0;i--)
		a[i]=a[i-1];
	a[i]=data;
	count++;
}
void add_end(int *a)
{
	int i,data;
	if(count==5)
	printf("\nthe array is full\n");
	printf("\nenter data\n");
	scanf("%d",&data);
	a[count++]=data;
}
void add_btw(int *a)
{
	if(count==5)
	printf("array is full\n");
	int i,data,pos;
	printf("\nenter the position\n");
	scanf("%d",&pos);
	printf("\nenter the data\n");
	scanf("%d",&data);
	if(pos>0 && pos<count)
	{
	for(i=count-1;i>0;i--)
	a[i+1]=a[i];
	a[pos-1]=data;
	}
	else
{printf("\nenter position starting with 1 between 1 to %d\n\n\n",count);return;}
	count++;
}
void del(int *a)
{
	int pos;
	printf("\nenter the position\n");
	scanf("%d",&pos);
	for(;pos<count;pos++)
		{a[pos-1]=0;
		a[pos-1]=a[pos];}
	if(pos==5)
	a[count-1]=0;
	count--;
	if(count==0)
	a[5]={0};
}
void disp(int *a)
{
	int i;
	printf("\narray is :\n");
	for(i=0;i<count;i++)
	printf(" %d ",a[i]);
	printf("\n");
}


		
		
		
	
	
	
	
		




	
		
