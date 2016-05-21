#include<stdio.h>
main()
{
	int i, n;
	char ch;
	int count = 0;
	printf("enter the value to find sum\n");
	scanf("%d", &n);

	printf("f:forloop\n w:while\n d:dowhile");
	while(1)
	{
	printf("enter the character to add\n");
	scanf(" %c",&ch);

	
	switch(ch)
	{
		
	     case 'f':
	
	         for(i=0;i<=n;i++)
	          {
	 	     count=count+i;
	          }
		    printf("%d\n",count);
		    break;
             case 'w':
		   while(i<=n)
			{
			    count=count+i;
			    i++;
			}
			printf("%d\n",count);
			break;
	      case 'd':
			
			do
			{
			        
				count=count+i;
				i++;
			}while(i<=n);
			 printf("%d\n",count);
			 break;
	      default : puts("invalid choice");
	}
	}
}

	
		
		
