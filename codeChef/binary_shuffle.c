#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>

/* Function to get no of set bits in binary
   representation of positive integer n */
unsigned int countSetBits(uint64_t n)
{
    unsigned int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

uint64_t power(uint64_t base, uint64_t powerRaised)
{
    if (powerRaised != 0)
        return (base*power(base, powerRaised-1));
    else
        return 1;
}

#if 0
uint64_t power(unsigned base, unsigned degree)
{
    uint64_t result = 1;
    uint64_t term = base;
    while (degree)
    {
        if (degree & 1)
            result *= term;
        term *= term;
        degree = degree >> 1;
    }
    return result;
}
#endif

uint64_t binShuffleEquel(uint64_t b)
{
    return b-1;
}

uint64_t binShuffleGreater(uint8_t srcCount, uint8_t dstCount)
{
    uint8_t diff = 0, tmp2 = 0, tmp4 = 0;
    uint64_t tmp1 = 0, tmp3 = 0;
    diff = srcCount - dstCount;
    tmp1 = power(2,diff+1)-1;
    tmp2 = srcCount - countSetBits(tmp1);
    tmp3 = power(2,tmp2)-1;
    tmp4 = 64 - countSetBits(tmp3);
    tmp3 <<= tmp4;

    return (tmp1 | tmp3);
}

uint64_t binShuffleLesser(uint8_t srcCount)
{
    uint64_t tmp;
    tmp = power(2,srcCount)-1;
    return (tmp <<= 1);
}

void main()
{
    uint64_t a = 0, b = 0;
    uint8_t aCount = 0, bMinusOneCount = 0, count = 0;
    uint32_t numOfOperation = 0;
    scanf("%d", &numOfOperation);

    while(numOfOperation--)
    {
        scanf("%" SCNu64 "%" SCNu64, &a, &b);
        //printf("%" PRIu64 " %" PRIu64 "\n", a, b);
        bMinusOneCount = countSetBits(b-1);
        if(a!=b && bMinusOneCount == 64)
        {
            printf("%d\n", -1);
            continue;
        }
        // 1. prefix zeroes are already added since unsigned int decimal is taken
        while(a!=b)
        {
            aCount = countSetBits(a);
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
        printf("%d\n", count);
        count = 0;
    }
    return;
}
