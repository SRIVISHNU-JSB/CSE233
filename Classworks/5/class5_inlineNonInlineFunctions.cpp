#include <iostream>

using namespace std;

//void add();

inline void add() //Declaration and Definition of Inline function using keyword: inline
{
	int a,b;
	cin>>a>>b;
	cout<<a+b;
}

int main()
{
	add();	
}

//void add()
//{
//	int a,b;
//	cin>>a>>b;
//	cout<<a+b;
//}

