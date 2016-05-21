#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *start;
void cnode(node*);
void disp();
node *getnode();
void joseph();
main()
{
	int a;
	node *newnode;
	start==NULL;
	printf("\nDo U Want To add Node\n");
	scanf("%d",&a);
	while(a)
	{
		newnode=getnode();
		cnode(newnode);
		printf("\nDo U Want to Add Another Node\n");
		scanf("%d",&a);
	}
	disp();
	joseph();
	disp();
}
node *getnode()
{

	node *p;
	int data;
	p=(node*)malloc(sizeof(node));
	p->next=NULL;
	printf("\nEnter the data\n");
	scanf("%d",&p->data);
	return p;
}


	
void cnode(node *q)
{
	node *temp=start;
	if(start==NULL)
	{	start=q;
		start->next=q;
		return;
	}
	while(temp->next!=start)
		temp=temp->next;
	temp->next=q;
	q->next=start;
}
void disp()
{
	node *p=start;
	do
	{
		printf(" %d ",p->data);
		p=p->next;
	}
	while(p!=start);
	printf("\n");
}
void joseph()
{
	int pos,i;
	node *temp=start,*p,*q;
	printf("\n***joseph's problem***\n");
	printf("enter the position\n");
	scanf("%d",&pos);
	while(temp!=temp->next)
	{
		for(i=0;i<pos;i++)
		{
			q=temp;
			temp=temp->next;
			p=temp->next;
		}
		free(temp);
		q->next=p;
		temp=p;
	}
	start=temp;
}
			
	





		


	
