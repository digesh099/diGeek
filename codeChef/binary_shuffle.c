#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

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

unsigned power(unsigned base, unsigned degree)
{
    unsigned result = 1;
    unsigned term = base;
    while (degree)
    {
        if (degree & 1)
            result *= term;
        term *= term;
        degree = degree >> 1;
    }
    return result;
}

uint8_t binShuffleEquel(uint8_t b)
{
    return b-1;
}

uint8_t binShuffleGreater(uint8_t srcCount, uint8_t dstCount)
{
    uint8_t diff, tmp1, tmp2, tmp3, tmp4;
    diff = srcCount - dstCount;
    tmp1 = power(2,diff+1)-1;
    tmp2 = srcCount - countSetBits(tmp1);
    tmp3 = power(2,tmp2)-1;
    tmp4 = 8 - countSetBits(tmp3);
    tmp3 <<= tmp4;

    return (tmp1 | tmp3);
}

uint8_t binShuffleLesser(uint8_t src)
{
    uint8_t tmp;
    tmp = power(2,src)-1;
    return (tmp <<= 1);
}

void main()
{
    uint8_t a = 0, b = 0, aCount = 0, bMinusOneCount = 0, count = 0;
    uint32_t numOfOperation = 0;
    scanf("%d", &numOfOperation);
    //printf("num of operation is : %d\n", numOfOperation);

    while(numOfOperation--)
    {
        scanf("%3" SCNu8 "%3" SCNu8, &a, &b);
        //printf("num of operation is : %d\n", numOfOperation);
        printf("%3" PRIu8 " %3" PRIu8 "\n", a, b);
        // 1. prefix zeroes are already added since unsigned int decimal is taken
        while(a!=b)
        {
            aCount = countSetBits(a);
            bMinusOneCount = countSetBits(b-1);
            if(aCount == bMinusOneCount) // final condition to reaching B
            {
                // shuffle operation
                a = binShuffleEquel(b);
            }
            else if(aCount > bMinusOneCount)
            {
                // shuffle operation
                a = binShuffleGreater(aCount, bMinusOneCount);
            }
            else if(aCount < bMinusOneCount)
            {
                // shuffle operation
                a = binShuffleLesser(aCount);
            }

            // +1 operation    
            ++a;
            ++count;

        }
        //printf("count to reach A --> B is %d\n", count);
        printf("%d\n", count);
        count = 0;
    }
    return;
}
