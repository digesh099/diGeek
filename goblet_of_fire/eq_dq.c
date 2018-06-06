#include<stdio.h>
    /*
       make Qnode : x,y values, self struct ptr
       Queue : Qnode, head, tail
       */
    /* 1.Enqueue:
       - isEmpty : add node. head and tail point to same node
       - compare the x with the existing node's x value
       - if found 'x'in any node :
       ----add the node behind it.
       ----if the match node's next == NULL then move the tail to newly added node
       - maximum queue capacity is (max x value * max y value)
       - allow enqueue operation only if (count < capacity)
       2. Dequeue:
       - isEmpty : Return. NA
       - free the currnt head and point head to head->next
       - store the x,y values
       */

typedef struct qNode
{
    int house;
    int houseId;
    struct qNode *next;
}qNode;

qNode *newNode()
{
    qNode *ptr;
    ptr = (qNode*) malloc(sizeof(qNode));
    if(ptr == NULL)
    {
        printf("Node creation fail\n");
    }
    ptr->house = 0;
    ptr->houseId = 0;
    ptr->next = NULL;

    return ptr;
}

int enQueue(qNode *node, qNode *nnode)
{
    qNode *tmpPtr;
    tmpPtr = node;

    if()

    while(tmpPtr->next != NULL)
    {
        tmpPtr = tmpPtr->next;
    }

    tmpPtr->next = nnode;
    return 1;
}

int deQueue(qNode *node)
{
    qNode *tmpPtr;
    tmpPtr = node->next;
    node->next = NULL;
    free(node);
    node = tmpPtr;
    return 1;
}

int main()
{
    int numOfOperation = 0, house = 0, houseId = 0;
    char qOperation, ch;
    qNode *nnode, *node;
    scanf("%d", &numOfOperation);
    node = newNode();
    while((ch = getchar()) != EOF)
    {
        scanf(" %c %d %d\n", &qOperation, &house, &houseId);
        //printf("\nnumOfOperation=%d qOperation=%c house=%d houseId=%d\n", numOfOperation, qOperation, house, houseId);
        switch(qOperation)
        {
            case 'E':
                enQueue(node, nnode);
                break;
            case 'D':
                if(node != NULL)
                {
                    deQueue(node);
                }
                break;
            default:
                printf("Invalid input given");
         }

    }
    return 1;

}

