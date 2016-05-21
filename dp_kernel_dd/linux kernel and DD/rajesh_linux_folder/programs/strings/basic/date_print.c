#include<stdio.h>

int main(void)
{
	int d, m, y;
	char *month[] = { "january", "february", "march", "april", "may", "june", "july", 
			  "august", "september", "october", "november", "december" };

	printf("enter the date (dd/mm/yyyy)   :  ");
	scanf("%d/%d/%d", &d, &m, &y);
	printf("%d %s %d \n",d, month[m - 1],y);
	return 0;
}
