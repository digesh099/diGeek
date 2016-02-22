#include<iostream>
using namespace std;
main()
{//int i;
int *p[2];
//for(i=0;i<2;i++)
 p[2]=new int[2];
*p[0]=5;
*p[1]=10;
//for(i=0;i<2;i++)	
	cout<<*p[0]<<*p[1]<<endl;
}

