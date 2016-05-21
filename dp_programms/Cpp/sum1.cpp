#include<iostream>
using namespace std;
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
	ABC sum(ABC,ABC);
};
void ABC::disp_ab()
{
	cout<<a<<endl;
	cout<<b<<endl;
}
ABC ABC::sum(ABC OBJ1,ABC OBJ2)
{
	ABC temp;
	temp.a=OBJ1.a+OBJ2.a;
	temp.b=OBJ1.b+OBJ2.b;
	return temp;
}
main()
{
	ABC obj1,obj2,obj3;
	obj1.get_ab(10,20);
	obj2.get_ab(2,3);
	obj3=obj3.sum(obj1,obj2);
	obj1.disp_ab();
	obj2.disp_ab();
	obj3.disp_ab();
}

