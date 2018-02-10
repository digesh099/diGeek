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
    printf("\n*")
    for (i = 0; i < ROW; i++)
    {
        for(j = 0; j < COLUMN; j++)
        {
            printf("%d\t", *((gm+j)+4*i));
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

void right(int gm[ROW][COLUMN])
{
    int i=0,j=0,k=0;
    for(i=0;i<ROW;i++)
    {
        for(k=0;k<COLUMN-1;k++)
        {
            for(j=COLUMN-1;j>0;j--)
            {
                if(gm[i][j] == gm[i][j-1]) //Disadavantage : it will add 0 + 0 as well which is not optimized way
                {
                    gm[i][j] += gm[i][j-1];
                }
                else if(gm[i][j-1])
                {
                    if(gm[i][j])
                    {
                        continue;
                    }
                    gm[i][j] = gm[i][j-1];
                }
                gm[i][j-1] = 0;
            }
        }
    }

    randomNumGen(gm);
    printMatrix(gm);
    return;
}

void left(int gm[ROW][COLUMN])
{
    int i=0,j=0,k=0;
    for(i=0;i<ROW;i++)
    {
        for(k=0;k<COLUMN-1;k++)
        {
            for(j=0;j<COLUMN-1;j++)
            {
                if(gm[i][j] == gm[i][j+1]) //Disadavantage : it will add 0 + 0 as well which is not optimized way
                {
                    gm[i][j] += gm[i][j+1];
                }
                else if(gm[i][j+1])
                {
                    if(gm[i][j])
                    {
                        continue;
                    }
                    gm[i][j] = gm[i][j+1];
                }
                gm[i][j+1] = 0;
            }
        }
    }

    randomNumGen(gm);
    printMatrix(gm);
    return;
}

void up(int gm[ROW][COLUMN])
{
    int i=0,j=0,k=0;
    for(i=0;i<COLUMN;i++)
    {
        for(k=0;k<ROW-1;k++)
        {
            for(j=0;j<ROW-1;j++)
            {
                if(gm[j][i] == gm[j+1][i]) //Disadavantage : it will add 0 + 0 as well which is not optimized way
                {
                    gm[j][i] += gm[j+1][i];
                }
                else if(gm[j+1][i])
                {
                    if(gm[j][i])
                    {
                        continue;
                    }
                    gm[j][i] = gm[j+1][i];
                }
                gm[j+1][i] = 0;
            }
        }
    }

    randomNumGen(gm);
    printMatrix(gm);
    return;
}

void down(int gm[ROW][COLUMN])
{
    int i=0,j=0,k=0;
    for(i=0;i<COLUMN;i++)
    {
        for(k=0;k<ROW-1;k++)
        {
            for(j=ROW-1;j>0;j--)
            {
                if(gm[j][i] == gm[j-1][i]) //Disadavantage : it will add 0 + 0 as well which is not optimized way
                {
                    gm[j][i] += gm[j-1][i];
                }
                else if(gm[j-1][i])
                {
                    if(gm[j][i])
                    {
                        continue;
                    }
                    gm[j][i] = gm[j-1][i];
                }
                gm[j-1][i] = 0;
            }
        }
    }

    randomNumGen(gm);
    printMatrix(gm);
    return;
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
                    printf("right key\n");
                    right(gameMatrix);
                    break;
                case 'D':
                    printf("left key\n");
                    left(gameMatrix);
                    break;
                case 'A':
                    printf("up key\n");
                    up(gameMatrix);
                    break;
                case 'B':
                    printf("down key\n");
                    down(gameMatrix);
                    break;
                default:
                    break;
            }
            // winCondition(); // 2048 stop looping
        }
    }
    return 0;
}
