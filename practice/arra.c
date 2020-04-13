#include<stdio.h>
#include<stdlib.h>

#if 0
int xyz(int raw, in col)
{
    int **ptr;
    ptr = malloc(raw*sizeof(int));
    *ptr = malloc(col*sizeof(int));

    ptr[raw][col];

}

char *str = "abc";
strcpy(str, "xyz");
printf("%s", str);

            1
        2       3
    4     5    6  7
#endif


//[]
int main()
{
    int **ptr;
    // [2][3]
    printf("%d\n", sizeof(int*));
    ptr = (int**)malloc(2*sizeof(int*));

    int i = 0;
    int j = 0;
    for(i = 0; i < 2; i++)
    {
        ptr[i] = malloc(3*sizeof(int));
        for(j = 0; j < 3; j++)
        {
            ptr[i][j] = 2;
        }
    }


    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d", ptr[i][j]);
        }
    }

    return 0;
}
#if 0
typedef struct node
{
    void data;
    struct *node;
}node;

add_node(node *node, void data)
{
    // iterate till last node
    while(node->next != NULL)
    {
        node = node->next;
    }

    // have a new node to be added and link at last
    node->next = malloc(sizeof(node));
    if(node->next == NULL)
    {
        return -1; //error in malloc
    }

    // 
    node->next->data = data;
    node->next->next = NULL:
}


void isPalindrome(char *string)
{
    // "abcba"
    // "avon sees nova"
    // 
}
#endif
