#include<stdio.h>

int func(int *ptr) {
    *ptr = 20;
  //int a = 20;
//   printf("ptr : %p\n", ptr);
  // ptr = &a;
 //  printf("*ptr : %d\n", *ptr);
  return 0;
}

int main()
{
   int p = 10;

   func(&p);
   printf("p : %d\n", p);
//   printf("&q : %p\n", &q);
//   printf("ptr : %p\n", ptr);
 //  printf("func() : %p\n", func);

//   func(ptr);

   return 0;
}

#if 0
void addNode(node *head, int data)
{
    node *new, *tmp;
    tmp = head;
    new = getNode(data);

    if(NULL == head)
    {
        head = new;
        return;
    }

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = new->next;
    tmp->data = new->data;
}
#endif
