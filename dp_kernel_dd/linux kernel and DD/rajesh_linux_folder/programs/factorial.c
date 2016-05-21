/* program to find the factorial of a given number */

#include<stdio.h>	

main()
{
	int c,n,fact=1;
	printf("enter a number to calculate its factorial value\n");
	scanf("%d",&n);
	for(c=1;c<=n;c++)
	fact=fact*c;
	printf("factorial of %d=%d\n",n,fact);
	return 0;
}
