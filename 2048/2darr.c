#include<stdio.h>

int main()
{
    int arr[4][4] = {{0,0,2,0},
                     {2,0,0,2},
                     {0,0,2,0},
                     {0,0,0,0}};
    int i, j;
    for (i = 0; i< 4; i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",arr[i][j]);
            printf("%p\t",&arr[i][j]);
        }
        printf("\n");
    }

    int *ptr;
    ptr = (int*)arr;
//    printf("%p\t",ptr);
    *((ptr + 4*0) + 0) = 7;
    *((ptr + 4*0) + 1) = 7;
    *((ptr + 4*0) + 2) = 8;
    *((ptr + 4*0) + 3) = 8;
    *((ptr + 4*1) + 0) = 9;
    *((ptr + 4*1) + 1) = 9;
    *((ptr + 4*1) + 2) = 10;
    *((ptr + 4*1) + 3) = 10;
    *((ptr + 4*2) + 0) = 11;
     for (i = 0; i< 4; i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",arr[i][j]);
//            printf("%p\t",&arr[i][j]);
        }
        printf("\n");
    }
   
 //   printf("%p\t",&arr[0][3]);
 //   printf("%p\t",(ptr + 0) + 3);
//    printf("\n%d ",arr[0][3]);

    return 0;
}
