 #include<stdio.h>
main()
{
	float a,b,c;
	scanf("%f",&a);
	b= a%4;
	c= b/2;
	if(c==0 && c==1)
	{
		printf("no is pwr of 2\n");
	}
	else
	{
		printf("no is not pwr of 2\n");
	}
}
