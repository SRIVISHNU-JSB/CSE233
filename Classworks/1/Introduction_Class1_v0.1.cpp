#include<iostream> // Header file which is a class like functions in c language
//using namespace std; //Standard Namespace which we use in the program like block numbers

int main() //In C++, The return type should be always integer unlike void/int used in C language
{
	// More than 1 function can cause ambiguity
	// There should be only one main() method/function should be in any program
	std::cout<<"Hello"<<std::endl; // Console Output // ostream class // "<< - Insertion Operator"
	int a=10;
	std::cout<<"Variable="<<a<<std::endl; // Format Specifiers are not required to be specified in C++
	int b;
	std::cin>>b; // Console Input belongs to istream class
	std::cout<<"b="<<b<<a;
}
