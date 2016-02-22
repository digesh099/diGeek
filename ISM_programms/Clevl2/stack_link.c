#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *start;
void push();
void pop();
void disp();
main()
{
	int op;
	start=NULL;
	while(1)
	{
	printf("Enter the stack operation\n");
	printf("1.push\n2.pop\n3.display\n4.exit\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:push();break;
		case 2:pop();break;
		case 3:disp();break;
		case 4:exit(0);
	}
	}
}
void push()
{
	node *p;
	int data;
	p=(node*)malloc(sizeof(node));
	p->next=NULL;
	printf("\nEnter the data whch u want to push\n");
	scanf("%d",&data);
	p->data=data;
	if(start==NULL)
	{
		start=p;
		return;
	}
	p->next=start;
	start=p;
}
void pop()
{
	if(start==NULL)
	{
		printf("\nStack is EMPTY\n");
		return;
	}
	free(start);
	start=start->next;
}
void disp()
{
	node *temp=start;
	while(temp!=NULL)
	{
		printf("  %d\n",*temp);
		temp=temp->next;
	}
}


	
