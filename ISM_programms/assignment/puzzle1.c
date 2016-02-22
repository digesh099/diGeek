#include<stdio.h>

int i,j,k,l;
main()
{
	int a[32],b,c,d,e,f;
l1:
	i==0;
	printf("enter the value\n");
	scanf("%d",&b);
	while((b/2)!=0)
	{
		a[i]=b%2;
		b=b/2;
		i++;
	}
	a[i]=1;
	
	for(k=31;k>=i+1;k--)
	{
		a[k]=0;
		printf("%d",a[k]);
	}
	for(j=i;j>=0;j--)
	{
		printf("%d",a[j]);
	}

	printf("\n\n 1.set\n 2.clear\n 3.return\n");
	scanf("%d",&c);
	if(c==1)
	{
		printf("\n enter the bit whch u want to set\n");
		scanf("%d",&d);
		a[d]=1;
		goto label;
	}
	else if(c==2)
	{
		printf("\nenter the bit whch u want to clear\n");
		scanf("%d",&e);
		a[e]=0;
		goto label;
	}
	else if(c==3)
	{
		goto l1;
	}
	else
	{
		goto l2;
	}
	label:
	for(l=31;l>=0;l--)
	{
		printf("%d",a[l]);
	}
	
		scanf("%d",&f);
		if(f==3)
		{
			goto l1;
		}
		else 
		{
			printf("\nu are successfully exited\n");
		}
	l2:
	printf("\nu are successfully exited\n");

	}	

