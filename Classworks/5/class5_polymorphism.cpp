#include <iostream>

using namespace std;

// Polymorphism through Function Overloading

class polymorphism
{
public:
	void calculate(int a, int b) // Function Overloading
	{
//		cin>>a>>b;
		cout<<a+b<<endl;
	}
	void calculate(int a, int b, int c)
	{
//		cin>>a>>b>>c;
		cout<<a+b+c<<endl;
	}
	void calculate(float a, float b, float c)
	{
//		cin>>a>>b>>c;
		cout<<a+b+c<<endl;
	}
};

int main() 
{
	polymorphism obj1, obj2, obj3;
	obj1.calculate(10,20,30);
	obj2.calculate(10, 20);
	obj3.calculate(2.2f, 2.3f, 2.4f);
	
}