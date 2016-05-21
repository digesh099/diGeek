#include<stdio.h>
void main()
{
	uint64_t num;
	printf("Enter the numberr in which you want to count zeros from 1: ");
	scanf("%d\n",num);
	findZeroCount(num);
}

void findZeroCount(uint64_t num)
{
	uint64_t temp1,temp2;
	temp1 = num/10;
	temp2 = (temp1/10) * 9 
