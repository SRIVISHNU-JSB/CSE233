#include <iostream>

using namespace std;

// WAP to find the area of square, rectange, circle using function overloading
// Create a class named shape and the function name area and there is no data member of the class.

class shape
{
public:
	void calculate(int a)
	{
		cout<<"Area of square: ";
		cout<<a*a<<endl;
	}
	void calculate(int a, int b)
	{
		cout<<"Area of rectangle: ";
		cout<<a*b<<endl;
	}
	void calculate(float a)
	{
		cout<<"Area of circle: ";
		cout<<3.14*a*a<<endl;
	}
};



int main() {
	
	shape s1,s2,s3;
	s1.calculate(10);
	s2.calculate(5,5);
	s3.calculate(5.55f);// Write f for float otherwise it will identified as double
	
}