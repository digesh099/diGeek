#include<stdio.h>
#include<stdint.h>
#include <inttypes.h>

/* Function to get no of set bits in binary
   representation of positive integer n */
unsigned int countSetBits(uint8_t n)
{
    unsigned int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void main()
{
    uint8_t a = 0, b = 0, aCount = 0, bMinusOneCount = 0, count = 0, tmp = 0;
    uint32_t numOfOperation = 0;
    scanf("%d", &numOfOperation);
    //printf("num of operation is : %d\n", numOfOperation);

    while(numOfOperation--)
    {
        scanf("%2" SCNu8 "%2" SCNu8, &a, &b);
        //printf("num of operation is : %d\n", numOfOperation);
        printf("%1" PRIu8 " %1" PRIu8 "\n", a, b);
        // 1. prefix zeroes are already added since unsigned int decimal is taken
        while(a!=b)
        {
            count++;
            aCount = countSetBits(a);
            bMinusOneCount = countSetBits(b-1);
            if(aCount == bMinusOneCount) // final condition to reaching B
            {
                // shuffle operation
                a = b-1;

                // addition operation
                ++a;
                continue;
            }
            // 2. shuffle operation
            if(aCount != 0x8)
                a <<= 1;

            // 3. addition operation
            ++a;
        }
        //printf("count to reach A --> B is %d\n", count);
        printf("%d\n", count);
        count = 0;
    }
    return;
}
