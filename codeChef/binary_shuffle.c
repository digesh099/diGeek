#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>

/* Function to get no of set bits in binary
   representation of positive integer n */
unsigned int countSetBits(unsigned long long int n)
{
    unsigned int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

unsigned long long int power(unsigned long long int base, unsigned long long int powerRaised)
{
    if (powerRaised != 0)
        return (base*power(base, powerRaised-1));
    else
        return 1;
}

unsigned long long int binShuffleEquel(unsigned long long int b)
{
    return b-1;
}

unsigned long long int binShuffleGreater(int srcCount, int dstCount)
{
    unsigned int diff = 0, tmp2 = 0, tmp4 = 0;
    unsigned long long int tmp1 = 0, tmp3 = 0;
    diff = srcCount - dstCount;
    tmp1 = power(2,diff+1)-1;
    tmp2 = srcCount - countSetBits(tmp1);
    tmp3 = power(2,tmp2)-1;
    tmp4 = 64 - countSetBits(tmp3);
    tmp3 <<= tmp4;

    return (tmp1 | tmp3);
}

unsigned long long int binShuffleLesser(int srcCount)
{
    unsigned long long int tmp;
    tmp = power(2,srcCount)-1;
    return (tmp <<= 1);
}

void main()
{
    unsigned long long int a = 0, b = 0;
    unsigned int aCount = 0, bMinusOneCount = 0, count = 0;
    unsigned int numOfOperation = 0;
    unsigned short int invalidFlag = 0;
    scanf("%d", &numOfOperation);

    while(numOfOperation--)
    {
        scanf("%lld %lld", &a, &b);
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
            // 2. shuffle binary. reaching s
            if(aCount == bMinusOneCount)
            {
                a = binShuffleEquel(b);
            }
            else if(aCount > bMinusOneCount)
            {
                if(bMinusOneCount == 0)
                {
                    printf("%d\n", -1);
                    invalidFlag = 1;
                    break;
                }
                a = binShuffleGreater(aCount, bMinusOneCount);
            }
            else if(aCount < bMinusOneCount)
            {
                a = binShuffleLesser(aCount);
            }

            // 3. s+1 operation
            ++a;
            ++count;

        }
        if(!invalidFlag) printf("%d\n", count);
        invalidFlag = 0;
        count = 0;
    }
    return;
}
