#include<stdio.h>
main()
{
	int *p,*q,ch,data,n=0,i=0;
	printf("do u want to add an elem.\n");
	scanf("%d",&ch);
	while(ch)
	{
		q=p;
		p=(int *)malloc(sizeof(int)*(n+1));
		printf("enter data\n");
		scanf("%d",&data);
		if(n>0)
		{
			for(i=0;i<n;i++)
				p[i]=q[i];
			free(q);
		}
		p[i]=data;
		n++;
		printf("do u want to add anoyher elem.\n");
		scanf("%d",&ch);
	}
	printf("elems are:\n");
	for(i=0;i<n;i++)
		printf("%d\n",p[i]);
}
