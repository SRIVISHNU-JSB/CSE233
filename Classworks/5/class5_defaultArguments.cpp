#include <iostream>

using namespace std;

// WAP to find the area of square, rectange, circle using function overloading
// Create a class named shape and the function name area and there is no data member of the class.

// Default Arguements
// 1. Default values for arguements should start with right to left in the parameters
// 2. The values passed from objects will be assigned from left to right to the variables

class shape
{
public:
//	void calculate(int a)
//	{
//		cout<<"Area of square: ";
//		cout<<a*a<<endl;
//	}
//	void calculate(int a, int b=10)
//	{
//		cout<<"Area of rectangle: ";
//		cout<<a*b<<endl;
//	}
	void calculate(int a, int b=10, int c=10)
	{
		cout<<"Area of rectangle: ";
		cout<<a*b<<endl;
	}
};

int main() {
	
	shape s1,s2,s3;
//	s1.calculate(10,12);
	s2.calculate(5,5,5);
	
	return 0;
	
}