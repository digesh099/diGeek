#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *stack;
void push(node**);
void stack_ini(node**);
void pop(node**);
void disp(node**);
main()
{
	int op;
	stack_ini(&stack);
	while(1)
	{
	printf("Enter the stack operation\n");
	printf("1.push\n2.pop\n3.display\n4.exit\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:push(&stack);break;
		case 2:pop(&stack);break;
		case 3:disp(&stack);break;
		case 4:exit(0);
	}
	}
}
void stack_ini(node **p)
{
	*p=NULL;
}
void push(node **q)
{
	node *p;
	int data;
	p=(node*)malloc(sizeof(node));
	p->next=NULL;
	printf("\nEnter the data whch u want to push\n");
	scanf("%d",&p->data);
	p->next=*q;
	*q=p;
}
void pop(node **p)
{
	if(*p==NULL)
	{
		printf("\nStack is EMPTY\n");
		return;
	}
	free(*p);
	*p=(*p)->next;
}
void disp(node **p)
{
	if(*p==NULL)
	{
		printf("\nStack is EMPTY\n");
		return;
	}
	node *temp=*p;
	while(temp!=NULL)
	{
		printf("  %d\n",*temp);
		temp=temp->next;
	}
}


	
