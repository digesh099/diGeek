#include<stdio.h>

//You are given  queries. Each query consists of a single number n You can perform any of the  operations on  in each move:
//1: If we take 2 integers  and  where n = axb (a!=1,b!=1) then we can change n = max(a,b)
//2: Decrease the value of  by .
//Determine the minimum number of moves required to reduce the value of  to .
//
//
//The first line contains the integer .
//The next  lines each contain an integer, .
// one of two operations:
// 1. chose two arbitary numbers such
//
// 25 : 5
// 5x5 = 5
// 5-1 = 4
// 2x2 = 2
// 2-1 = 1
// 1-1 = 0
//
// 24 : 2,3,4,6,8,12,    5
// 6x4 = 6
// 3x2 = 3
// 3-1 = 2
// 2-1 = 1
// 1-1 = 0
//
// 27 : 5
// 9x3 = 9
// 3x3 = 3
// 3-1 = 2
// 2-1 = 1
// 1-1 = 0
//
// 59 : 9
// 59-1 = 58
// 2x29 = 29
// 29-1 = 28
// 7x4  = 7
// 7-1  = 6
// 3x2  = 3
// 3-1  = 2
// 2-1  = 1
// 1-1  = 0
//
// 52 : 6
// 4x13 = 13
// 13-1 = 12
// 4x3  = 4
// 2x2  = 2
// 2-1  = 1
// 1-1  = 0
//
// 4 : 3
// 5 : 4
// 6 : 4
// 7 : 5
// 8 : 4
// 9 : 4
// 10 : 5
// 11 : 6
// 12 : 4
// 13 : 5
// 14 : 6
// 15 : 5
// 16 : 4
// 17 : 5
// 18 : 5
// 19 : 6
// 20 : 5
//
// 1,2,3,3,4,4,5,4,4,5,6,4,5,6,5,4,5,5,6,5
//
// 8024 : 4012x2: 2006x2x2: 1003x2x2x2
// 1000 : 500x2:250x2x2:125x2x2x2:5x5x5x2x2x2
// 24   : 12x2:6x2x2:3x2x2x2
// 1015 : 203x5
// 15 : 5x3
//
// 1. return 3 if n<=3
// 2. check if it is n%2 || n%3 || n%5
// 3. if n%2=0 then loop on checking until n==2
// 4. if n%2!=0 detected during the loop then proceed for n%3=0
// 5. if n%5=0 then loop until n==5
// 6. do multiplication of 2x3 or 3x5 or 2x5 or 2x3x5 and generate a
// 7. do n divide by ans from 7 and generate b
// 8. do max(a,b) and return max value
// 9. check if it is prime number. if it is primenumber then do n-1 and start from step 2 again
// 10. loop step 2 to 9 until n==0 and keep increment result

int generateMaxOfAB(int n)
{
    short int n2 = 1, n3 = 1, n5 = 1, i2=1,i3=1,i5=1;
    int tmp = n;
    while(0 == n%2)
    {
        n /= 2;
        n2 = 2;
        i2 = 2;
    }
    while(0 == n%3)
    {
        n /= 3;
        n3 = 4;
        i3 = 3;
    }
    while(0 == n%5)
    {
        n /= 5;
        i5 = 5;
    }

    if(1 == n2*n3*n5)
    {
        return tmp;
    }
    else if(tmp == n2*n3*n5)
    {
        if(n2 & 0x1 || n3 & 0x1)
        {
            return n5;
        }
        else if(n5 & 0x1)
        {
            return n3;
        }
    }
    
    return i2*i3*i5;
}

int downToZero(int n)
{
    int result = 0;
    if(n<=3)
    {
        return 3;
    }

    // iterate until n down to 0
    while(n)
    {
        // check if it needs to perform N-1 operation
        if(n%2!=0 || n%3!=0 || n%5!=0)
        {
            n--;
            result++;
        }
        // perform max(a,b) operation if possible
        n = generateMaxOfAB(n);
        if(n<=3)
        {
            result += 3;
            break;
        }
    }

    return result;
}

int main()
{
    int t = 0;
    int n = 0;
    int i = 0;
    
    scanf("%d", &t);
    for(i = 0; i<t; i++)
    {
        scanf("%d", &n);
        printf("%d", generateMaxOfAB(n));
    }

    return 0;
}
