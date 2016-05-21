#include<iostream>
using namespace std;
class abc
{
	int tot,a,b,c;
	public:
	void take();
	void disp();
};
void abc::take()
{
	cout<<"enter a,b,c value="<<endl;
	cin>>a>>b>>c;
}
void abc::disp()
{
	tot=a+b+c;
	cout<<"tot="<<tot<<endl;
}
main()
{
	abc obj;
	obj.take();
	obj.disp();
}
