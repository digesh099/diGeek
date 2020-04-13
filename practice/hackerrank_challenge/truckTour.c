#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
#define DP printf
#else
#define DP //
#endif

/*
 * 1. start from the first combination. check if current combination is n-1. if it is then return mark value
 * 2. check if it is possible to start from here and reach to next destination
 * 3. if you can reach to next destination go to 2
 * 4. if not then backtrack and return mark=-1 to start and take +1 combination and restart from 1
 */ 

bool truckTraverse(int **p, long int numOfPetrolPump, int petrol_available, int n, int count)
{
    if(n == count)
    {
        return true;
    }

    DP("numOfPetrolPump: %d petrol_available = %d count = %d\n", numOfPetrolPump, petrol_available, count);
    if(petrol_available < p[numOfPetrolPump][1])
    {
        return false;
    }

    petrol_available -= p[numOfPetrolPump][1];

    // it's a circular buffer
    int idx = (numOfPetrolPump+1)%n;
    return truckTraverse(p, idx, petrol_available+p[idx][0], n, count+1);
}

int truckTour(int petrolpumps_rows, int petrolpumps_columns, int** petrolpumps) {

    int i = 0;
    for(i = 0 ; i < petrolpumps_rows; i++)
    {
        DP("combination : %d\n", i);
        if(true == truckTraverse(petrolpumps, i, petrolpumps[i][0], petrolpumps_rows, 0))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n = 0;
    int a = 0;
    int d = 0;
    int i = 0;
    long int result = 0;
    scanf("%d", &n);

    int **q = malloc(n* sizeof(int*));
    for(i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &d);
     
        q[i] = malloc(2*sizeof(int));
        q[i][0] = a;
        q[i][1] = d;
    }

    result = truckTour(n, 2, q);

    if(result > 0)
        printf("%d\n", result);

    return 0;
}
