#include<stdio.h>
void sort(char *x,char *y);
void swap(char *x,char *y);
static i;
main()
{
	char *str[2],s[5];
	printf("enter the strings :\n");
	for(i=0;i<2;i++)
	{
		scanf("%s",s);
		str[i]=(char*)malloc(sizeof(s));
		strcpy(str[i],s);
	}
	sort(str[0],str[1]);
}
void sort(char *x,char *y)
{
	
	for(i=0;i<2;i++)
		{if(x[i]>y[i])
		 {swap(x,y);
		 break;}
		}	
//	printf("%s\t%s\n",x,y);
}
void swap(char *x,char *y)
{
	char *p;
	p=x;
	strcpy(x,y);
	//strcpy(y,p);
	
	
	/*char p[10];
	for(i=0;(*(x+i)!='\n'|| *(y+i)!='\n');i++)
	{p[i]=x[i];
	x[i]=y[i];
	y[i]=p[i];}*/
	printf("%s\n%s\n",x,p);
}
	
