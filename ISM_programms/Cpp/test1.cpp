#include<iostream>
using namespace std;
namespace first
{
	int a=10;
	float b=2.5;
}
namespace sec
{
	int b=2;
	float a=5.5;
}
main()
{
	using first::a;
	using sec::b;
	cout<<"a="<<a;
//	using namespace sec;
	cout<<"b="<<b;
}	
	
