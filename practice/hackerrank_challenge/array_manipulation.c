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


long int arrayManipulation(int n, int queries_rows, int queries_columns, int** queries) {
    int l = 0;
    int r = 0;
    int i = 0;
    int *arr = malloc((n+2)*sizeof(int));
    memset(arr,0x0,(n+2)*sizeof(int));
    int final_l = 0;
    int final_r = 0;
    long int maxnum = 0;

    for(i =0; i<queries_rows; i++)
    {
        l = queries[i][0];
        r = queries[i][1]+1;
        arr[l] += queries[i][2];
        //arr[r] += (queries[i][2])-(2*queries[i][2]);
        arr[r] -= queries[i][2];
        
        int j =0;
        DP("{");
        for(j=0;j<n+1;j++)
        {
            DP("%d,", arr[j]);
        }
        DP("}\n");

        if(l < final_l )
        {
            final_l = l;
        }
        
        if(r > final_r)
        {
            final_r = r;
        }
    }
    int tmp = 0;
    DP("{");
    for(i = 0; i<n+2; i++)
    {
        tmp = arr[i] + tmp;
        arr[i] = tmp;
        DP("%d,", arr[i]);
        
        if(arr[i] > maxnum)
        {
            maxnum = arr[i];
        }
    }
    DP("}\n");

    free(arr);
    
    return maxnum;
}

int main()
{
    int n = 0;
    int m = 0;
    int a = 0;
    int b = 0;
    int k = 0;
    int i = 0;
    int maxnum = 0;
    scanf("%d", &n);
    scanf("%d", &m);

     DP("========= inputs =========\n");
    int **q = malloc(m * sizeof(int*));
    for(i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &k);
        DP("n : %d m = %d a = %d b = %d k = %d\n", n, m, a, b, k);
     
        q[i] = malloc(3*sizeof(int));
        q[i][0] = a;
        q[i][1] = b;
        q[i][2] = k;
    }

    maxnum = arrayManipulation(n, m, 3, q);

    printf("%d\n",maxnum);

    return 0;
}
