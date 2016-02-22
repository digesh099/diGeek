#include<iostream>
using namespace std;
class XYZ;
class ABC
{
	int a,b;
	public:
	void get_ab(int A,int B)
	{
		a=A;
		b=B;
	}
	void disp_ab();
	friend int sum(ABC,XYZ);
};
class XYZ
{
	int x,y;
	public:
	void get_xy(int X,int Y)
	{
		x=X;
		y=Y;
	}
	void disp_xy();
	friend int sum(ABC,XYZ);
};
void ABC::disp_ab()
{
	cout<<"a="<<a<<endl<<"b="<<b<<endl;
}

void XYZ::disp_xy()
{
	cout<<"x="<<x<<endl<<"y="<<y<<endl;
}
int sum(ABC A1,XYZ X1)
{
	int total;
	cout<<"a="<<A1.a<<endl<<"b="<<A1.b<<endl;
	cout<<"a+b="<<A1.a+A1.b<<endl;
	cout<<"x="<<X1.x<<endl<<"y="<<X1.y<<endl;
	cout<<"x+y="<<X1.x+X1.y<<endl;
	total=A1.a+A1.b+X1.x+X1.y;
	return total;
}
main()
{
	int a;
	ABC obj1;XYZ obj2;
	obj1.get_ab(10,20);
	obj1.disp_ab();
	obj2.get_xy(50,60);
	obj2.disp_xy();
	a=sum(obj1,obj2);
	cout<<"total="<<a<<endl;
}
