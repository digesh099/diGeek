#include<stdio.h>

int main()
{
    int freq[26] = {1,2,3};

    int a;
    while(1)
    {
        scanf("%d", &a);
        printf("%x\n", a);
        printf("%x\n", ~a);
        printf("%d\n", a);
        printf("%d\n", ~a+1);
    }
    return 0;
}
