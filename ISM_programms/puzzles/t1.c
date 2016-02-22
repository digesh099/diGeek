#include<stdio.h>
#include"t21.c"
//int i=1;
int next();
int last();
int new(int);


main()
{
auto int i,j;
				
i=reset();
						
for(j=1;j<=3;j++)
{
											printf("%d %d",i,j);
											printf(" %d ",next());
																
											printf(" %d ",last());
																				
											printf(" %d ",new(i+j));
																				}

}
static int i=10;
next()
{
	return(i+=1);
}
last()
{
	return(i-=1);
}
new(int i)
{
	static int j=5;
	return(i=j+=1);
}
		
				
