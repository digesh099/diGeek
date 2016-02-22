#include<iostream>
using namespace std;
class test
{
	int a;
	public:
	int b;
	void get_ab(int x,int y)
	{
		a=x;
		b=y;
		disp();
	}
	void disp();
	void large();
};
void test::large()
{
	if(a>b)
		cout<<"a is large"<<endl;
	else
		cout<<"b is large"<<endl;
}
void test::disp()
{
	cout<<"a="<<a<<endl<<"b="<<b;
	//get_ab(75,100);
	large();
}

main()
{
	//int a;
	test obj;
	obj.b=5;
	obj.get_ab(20,30);
	obj.b=5;
	obj.disp();
	cout<<endl<<sizeof(test);
	//obj.disp();
}

	
