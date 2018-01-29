//     0 1 2 3
//  ++++++++++
//  0+ 0 0 0 0
//  1+ 0 2 2 0
//  2+ 0 0 2 0
//  3+ 0 0 0 0

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW     4
#define COLUMN  4

int randomNum(int min, int max){
      return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int randomNumGen(int *gm)
{
    int row = 0, column = 0, randNum = 0, emptyFlag = 0;
    do
    {
        randNum = randomNum(0,15);
        printf("matrix position is is %d\n", randNum);
        row = randNum/4;
        column = randNum%4;
        emptyFlag = 0;
        if (!(*((gm + column)+4*row)))
        {
            *((gm + column)+4*row) = 2;
            emptyFlag = 1;
        }
    }while(!emptyFlag);
    return 0;
}

void printMatrix(int *gm)
{
    int i = 0, j = 0;
    for (i = 0; i < ROW; i++)
    {
        for(j = 0; j < COLUMN; j++)
        {
            printf("%d ", *((gm+j)+4*i));
        }
        printf("\n");
    }
    return;
}

void initGameSpace(int *gm)
{
    printMatrix(gm);
    randomNumGen(gm);
    printMatrix(gm);
    return;
} 

// 1. compare column's
// 2. if match the elements of the same index then add them at rigtmost side
// 3.

void right(int *gm)
{

}

int main()
{
    char key;
#if 0
    int gameMatrix[ROW][COLUMN] = {{2,2,2,2},
                                   {2,2,2,2},
                                   {2,2,0,2},
                                   {2,2,2,2}};
#endif
    int gameMatrix[ROW][COLUMN] = {0};
    initGameSpace(gameMatrix); // the first matrix having one box filled with number 2 at random position
    //2. identify the keystrok : left,right,up and down
    while(1)
    {
        key = getchar();
        if(key == 27)
        {
            getchar();
            switch(getchar())
            {
                case 'C':
                    right(gameMatrix);
                    printf("right key\n");
                    break;
                case 'D':
                    left(gameMatrix);
                    printf("left key\n");
                    break;
                case 'A':
                    up(gameMatrix);
                    printf("up key\n");
                    break;
                case 'B':
                    down(gameMatrix);
                    printf("down key\n");
                    break;
                default:
                    break;
            }
            // winCondition(); // 2048 stop looping
        }
    }
    return 0;
}
