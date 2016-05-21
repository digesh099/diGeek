#include<iostream>
using namespace std;

class abc
{int a,b;
public:
void get(int x,int y)
{a=x;
b=y;
	}
	void disp()
	{cout<<"a+ib="<<a<<"+i"<<b<<endl;
		}
		friend void sum(abc,abc);
		friend void diff(abc,abc);
	};
	
	void diff(abc o1,abc o2)
	{cout<<"sum="<<o1.a-o2.a<<"+i"<<o1.b-o2.b<<endl;
		}
void sum(abc o1,abc o2)
{cout<<"diff="<<o1.a+o2.a<<"+i"<<o1.b+o2.b<<endl;
	}
main()
{abc o1,o2;
o1.get(10,30);
o2.get(4,20);
o1.disp();
o2.disp();
sum(o1,o2);
diff(o1,o2);
	}
