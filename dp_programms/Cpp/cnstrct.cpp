#include<iostream>
using namespace std;
class abc
{
	int a,b;
	public:
	abc()
	{
		a=10;
		b=20;
		cout<<"construct invoked"<<endl;
	}
	abc(int A)
	{	cout<<"\n***a="<<a<<endl;
		a=A;
		cout<<"a="<<a<<endl;
	}
	abc(abc &x)
	{
		a=x.a;
	//	b=y;
	//	cout<<"a and b="<<a<<"\t"<<b<<endl;
	}
		
		
	void get(int x,int y)
	{
		a=x;
		b=y;
	}
	void disp();
/*	{
		cout<<"a="<<a<<"\n"<<"b="<<b;
	}*/
};
main()
{
	abc a1;
	a1.disp();
	//a1.get(5,7);
	abc a2(100);
	a2.disp();
	abc a3(a2);
	a3.disp();

//	abc a3(200,400);
//	a1.disp();
	
}
	void abc::disp()
	{
		cout<<"a="<<a;//"\n"<<"b="<<b;
	}
/*	void abc::get(int x,int y)
	{
		a=x;
		b=y;
	}*/
