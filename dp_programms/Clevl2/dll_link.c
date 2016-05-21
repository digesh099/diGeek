#include<stdio.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
typedef struct node node;
node *start;
int count=0;

void add();
void del();
void display();
void add_beg(node*);
void add_end(node*);
void add_btw(node*);
void del_beg();
void del_end();
void del_btw();
void *getnode();
void ascend();
void rever();
main()
{	
	int a;
	start=NULL;
	while(1)
	{
	printf("\nEnter the operation :\n");
	printf("\n1.add\n2.delete\n3.Display\n4.Ascending\n5.Reverse\n6.Exit");
	scanf("%d",&a);
	switch(a)
	{
		case 1:add();break;
		case 2:del();break;
		case 3:display();break;
		case 4:ascend();break;
		case 5:rever();break;
		case 6:exit(0);
	}
	}
}
void add()
{
	int a;
	node *newnode;
	while(1)
	{
	printf("\n1.add_beg\n2.add_end\n3.add_btw\n4.return\n");
		scanf("%d",&a);
		if(a==1||a==2||a==3)
		newnode=getnode();
		switch(a)
		{
			case 1:add_beg(newnode);break;
			case 2:add_end(newnode);break;
			case 3:add_btw(newnode);break;
			case 4:return;
		}
	}
}	
void *getnode()
{
	node *p;
	p=(node*)malloc(sizeof(node));
	printf("\nenter data\n");
	scanf("%d",&p->data);
	p->next=NULL;
	p->prev=NULL;
	return p;
}
void add_beg(node *q)
{
	if(start==NULL)
	{
	start=q;
	count++;
	return;
	}
	q->next=start;
	start->prev=q;
	start=q;
	count++;
}
void add_end(node *q)
{
	node *temp=start;
	if(start==NULL)
	{
	start=q;
	count++;
	return;
	}
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=q;
	q->prev=temp;
	count++;
}
void add_btw(node *q)
{
	node *temp=start;
	int i,pos;
	
	if(start==NULL)
	{
		printf("\nEMPTY\n");
		return;
	}
	printf("\nEnter Position : ");
	scanf("%d",&pos);
	for(i=1;i<pos;i++)
	{
		temp=temp->next;
	}
	q->prev=temp;
	q->next=temp->next;
	temp->next=q;
	q->next->prev=q;
}
void del()
{
	int a;
	while(1)
	{
	printf("\n1.del_beg\n2.del_end\n3.del_btw\n4.return\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:del_beg();break;
		case 2:del_end();break;
		case 3:del_btw();break;
		case 4:return;
	}
	}
}
void del_beg()
{
	if(start==NULL)
	{printf("\nEMPTY\n");
	return;}
	free(start);
	start=start->next;
	start->prev=NULL;
	count--;

}
void del_end()
{
	node *temp=start;
	if(start==NULL)
	{printf("\nEMPTY\n");
	return;}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->prev->next=NULL;
	free(temp);
}
void del_btw()
{
	node *temp=start;
	int pos,i;
	if(start==NULL)
	{printf("\nEMPTY\n");
	return;}
	printf("\nEnter the position : ");
	scanf("%d",&pos);
	for(i=0;i<pos;i++)
		{
		temp=temp->next;
		}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
	count--;
}

void display()
{
	node *temp=start;
	while(temp!=NULL)
		{
		printf(" %d ",temp->data);
		temp=temp->next;
		}
		printf("\n");
	//	printf("\n**counter is %d ** ",count);
}
void ascend()
{
	node *p=start;
	int a,i;
	for(i=0;i<count;i++)
	{
	while(p->next!=NULL)
	{
		if(p->data > (p->next)->data)
		{
		a=p->data;
		p->data=p->next->data;
		p->next->data=a;
		p=p->next;
		}
		else
		p=p->next;
	}
	p=start;
	}
}
void rever()
{
	node *temp1=start,*temp2=NULL;
	while(start!=NULL)
		{
			start=start->next;
			temp1->next=temp2;
			temp2=temp1;
			temp1=start;
		}
		start=temp2;
}





			






