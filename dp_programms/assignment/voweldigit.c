#include<stdio.h>
main()
{
	int s=0,v=0,c,b,i,d=0;
	char a[100];
	printf("enter the string : ");
	gets(a);
	b=strlen(a);

	for(i=0;i<b;i++)
	{
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||
			a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U')
		v++;

		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||
			a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')
		d++;

		if(a[i]==' ')
		s++;
	}
	c=b-(v+d+s);
	printf("\nstrng length : %d\n",b);
	printf("no vowels are : %d\n",v);
	printf("no of digits are : %d\n",d);
	printf("no of spaces are : %d\n",s);
}
	
	
	
	
