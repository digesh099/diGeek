#include<stdio.h>
void push(int*,int);
int pop(int*);
void disp(int*);
int top=-1;
int a[5];
main()
{
	int op,data,val;
	while(1)
	{
	printf("Enter the operation which u want to perform\n");
	printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:printf("Enter data to push\n");
			scanf("%d",&data);
			push(a,data);
			break;
		case 2:val=pop(a);
			printf("\n%d value is poped\n",val);
			break;
		case 3:disp(a);break;
		case 4:exit(0);


	}
	}
}
void push(int *a,int data)
{
	if(top==5)
	{
		printf("\nstack is full\n");
		return;
	}
	a[++top]=data;
}
 pop(int *a)
{
	if(top==-1)
	{
		printf("\nstack is full\n");
		return;
	}
	return(a[top--]);
}
void disp(int *a)
{
	if(top==-1)
	{
		printf("\nstack is EMPTY\n");
		return;
	}
	int i;
	printf("\ncurrent Stack is:\n\n");
	for(i=top;i>=0;i--)
		printf("  %d\n",a[i]);
}
		

	
