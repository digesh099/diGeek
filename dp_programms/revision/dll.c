#include<stdio.h>
struct node
{
	struct node *prev;
	int data;
	struct 	node *next;
};
typedef struct node node;
node *start;
void add();
void del();
void disp();
void add_beg(node*);
void add_end(node*);
void add_btw(node*);
void del_beg();
void del_end();
void del_btw();
node *getnode();

int ch;
main()
{
	start==NULL;
	while(1)
	 {
		 printf("select the operation\n");
		 printf("1.ADD\n2.DELETE\n3.DISPLAY\n4.BACK\n");
		 scanf("%d",&ch);
		 switch(ch)
		 {
			 case 1:add();break;
			 case 2:del();break;
			 case 3:disp();break;
			 case 4:exit(0);
		 }
	 }
}
node *getnode()
{
	node *p;
	p=(node*)malloc(sizeof(node));
	printf("enter the data\n");
	scanf("%d",&p->data);
	p->next=NULL;
	p->prev=NULL;
	return(p);
}
void add()
{
	node *nn;
	while(1)
	{
	printf("1,ADD_BEG\n2.ADD_END\n3.ADD_BTW\n4.DISPLAY\n5.BACK\n");
	scanf("%d",&ch);
	if(ch==1|ch==2|ch==3)
	{
		nn=getnode();
	}
		
	switch(ch)
	{
		case 1:add_beg(nn);break;
		case 2:add_end(nn);break;
		case 3:add_btw(nn);break;
		case 4:disp();break;
		case 5:return;
	}
	}
}
void add_beg(node *new)
{
	if(start==NULL)
	{
		start=new;
		return;
	}
	new->next=start;
	start->prev=new;
	start=new;
}
void add_end(node *new)
{
	node *temp=start;
	if(start==NULL)
	{
		printf("EMPTY\n");
		return;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new;
	new->prev=temp;
}
void add_btw(node *new)
{
	node *temp=start;
	int pos,i;
	if(start==NULL)
	{
		printf("EMPTY\n");
		return;
	}
	printf("enter the position : ");
	scanf("%d",&pos);
	for(i=0;i<pos;i++)
	{
		temp=temp->next;
	}
	new->next=temp;
	new->prev=temp->prev->next;
	temp->prev->next=new;
	temp->prev=new;
}
void del()
{
	node *temp;
	while(1)
	{
	printf("1.DEL_BEG\n2.DEL_END\n3.DEL_BTW\n4.DISPLAY\n5.BACK\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:del_beg();break;
		case 2:del_end();break;
		case 3:del_btw();break;
		case 4:disp();break;
		case 5:return;
	}
	}
}
void del_beg()
{

	if(start==NULL)
	{
		printf("EMPTY\n");
		return;
	}
	free(start);
	start=start->next;
	start->prev=NULL;
	
}
void del_end()
{
	node *temp=start;
	if(start==NULL)
	{
		printf("EMPTY\n");
		return;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	free(temp);
	temp->prev->next=NULL;
}
void del_btw()
{
	int pos,i;
	node *temp=start;
	printf("enter the position : ");
	scanf("%d",&pos);
	for(i=0;i<pos;i++)
	{
		temp=temp->next;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
}
void disp()
{
	node *temp=start;
	while(temp!=NULL)
	{
		printf(" %d ",temp->data);
		temp=temp->next;
	}
}
		













	
	
	





















	
	
	
	


















	

		 
		 
