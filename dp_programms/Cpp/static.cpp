#include<iostream>
using namespace std;
class ABC
{
	int a;
	static int count;
	public:
	void get_a();
	static void disp()
	{
		cout<<"count="<<count;
	}
};
//int ABC::count;

void ABC::get_a()
{
	a=++count;
	cout<<"a="<<a;
}
/*static void disp()
{
	cout<<"count="<<count;
	cout<<"count="<<count;
}*/
int ABC::count;
//void ABC::disp();

main()
{
	ABC obj1,obj2,obj3;
	obj1.get_a();
	obj2.get_a();
	obj3.get_a();
	obj1.disp();
}
	
