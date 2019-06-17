#include<stdio.h>

int main()
{
    // 1. get inputs
    short int T = 0, p = 0;
    char s[1000];
    short int absent[1000];
    short int result[200];
    short int idx = 0, i = 0;
    float countP = 0, D = 0;
   
    scanf("%d", &T);
    for(p = 0; p < T; p++)
    {
        scanf("%f", &D);
        scanf("%s", s);

        //printf("D=%d, arr:%c %c\n", D, s[0],s[1]);

        // 2. get the No. of 'A's from the input and take the index of each A's position
        for(idx = 0; idx < D; idx++)
        {
            if(s[idx] == 'p' || s[idx] == 'P')
            {
                countP++;
            }
        }

        for(idx = 2; idx < D-2; idx++)
        {
            if(s[idx] == 'a' || s[idx] == 'A')
            {
                absent[i++] = idx;
            }
        }


        // 3. calculate if it is <0.75
        if(countP/D < 0.75)
        {
            short int countFlagLeft = 0, countFlagRight = 0, minProxyCount = 0;
            // 4. check the proxy condition d-1,d-2 and d+1,d+2 at least one present
            for(idx = 0; idx < i; idx++)
            {
                if(absent[idx]-1 >= 0)
                {
                    if(s[absent[idx]-1] == 'P' || s[absent[idx]-1] == 'p')
                    {
                        countFlagLeft = 1;
                    }
                }

                if(absent[idx]-2 >= 0)
                {
                    if(s[absent[idx]-2] == 'P' || s[absent[idx]-2] == 'p')
                    {
                        countFlagLeft = 1;
                    }
                }

                if(absent[idx]+1 <= D)
                {
                    if(s[absent[idx]+1] == 'P' || s[absent[idx]+1] == 'p')
                    {
                        countFlagRight = 1;
                    }
                }

                if(absent[idx]+2 <= D)
                {
                    if(s[absent[idx]+2] == 'P' || s[absent[idx]+2] == 'p')
                    {
                        countFlagRight = 1;
                    }
                }

                if(countFlagLeft && countFlagRight)
                {
                    minProxyCount++;
                    countP++;
                    if(countP/D >= 0.75)
                        break;
                    countFlagLeft=countFlagRight=0;
                }
            }
            if(minProxyCount)
            {
             //   printf("%d\n",minProxyCount);
                result[p] = minProxyCount;
            }
            else
            {
               // printf("-1\n");
                result[p] = -1;
            }
        }
        else
        {
            //printf("0\n");
            result[p] = 0;
        }
        i = 0;
        countP = 0;
    }

    for(idx = 0; idx < T; idx++)
        printf("%d\n", result[idx]);

    return 0;
}
