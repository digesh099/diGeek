#include<iostream>
using namespace std;
void fun(int a,int b=5,int c=10);
main()
{
	int a=10;
	cout<<a<<endl;
	fun(7);
	cout<<a<<endl;
}
void fun(int a,int b,int c)
{	int x;
	x=a*b*c;
	cout<<x;
}
