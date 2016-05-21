#include<stdio.h>
main()
{
int n,reverse=0,rem,temp;
printf("enter an integer");
scanf("%d",&n);
temp=n;
while(temp!=0)
{
rem=temp%10;
reverse=reverse*10+rem;
temp/=10;
}
if(reverse==n)
printf("%d is palindrom.",n);
else
printf("%d is not a palindrom.",n);
return 0;
}

