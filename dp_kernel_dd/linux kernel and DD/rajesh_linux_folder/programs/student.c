#include<stdio.h>
struct st
{
	int data;
	char n[10];
	struct st *next;
};
void print (struct st *);
void add(struct st **);
main()
{
	struct st *head = 0;
	char ch;
	while(1)
	{
	  printf("p:print\na:add\ne:exit\n");
	  printf("enter the choice\n");
	  scanf(" %c", &ch);
	switch(ch)
	{
	  case 'a':add(&head);
		   break;
	  case 'p':print(head);
		   break;
	  case 'e':exit(0);
		   break;
	  default:printf("invalid choice\n");
	}
	}
}
void add(struct st **ptr)
{
	struct st *nu,*mov=*ptr;
	nu=malloc(sizeof(struct st));
	printf("enter the data and name\n");
	scanf("%d %s",&nu->data,nu->n);
	if(*ptr == 0)
	{
	  *ptr = nu;
	  nu->next = 0;
	}
	else
	{
	  while(mov->next!=0)
	  {
	     mov = mov->next;
	  }
	     mov->next = nu;
	     nu->next = 0;
	}
}
void print(struct st *ptr)
{
	while(ptr)
	{
	  printf("%d %s\n",ptr->data,ptr->n);
	  ptr=ptr->next;
	}
}


















