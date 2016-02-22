#include<iostream>
using namespace std;
class cal
{
	int a,b;
	public:
	int enter();
	int take();
	void tot(int,int);
	void disp();
};
int cal::enter()
{
	cout<<"enter values of a & b"<<endl;
	cin>>a>>b;
	return a;
}
int cal::take()
{
	return b;
}
void cal::tot(int x,int y)
{
	a=x;
	b=y;
}
void cal::disp()
{
	cout<<"a="<<a<<"\nb="<<b<<endl;
}
main()
{
	int x,y,z,p;
	cal obj1,obj2,obj3;
	x=obj1.enter();
	y=obj2.enter();
	z=x+y;
	x=obj1.take();
	y=obj2.take();
	p=x+y;
	obj3.tot(z,p);
	obj3.disp();
}
	
	
