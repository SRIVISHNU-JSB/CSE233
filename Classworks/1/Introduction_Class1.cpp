#include<iostream> // Header file which is a class like functions in c language
using namespace std; //Standard Namespace which we use in the program like block numbers

int main() //In C++, The return type should be always integer unlike void/int used in C language
{
	// More than 1 function can cause ambiguity
	// There should be only one main() method/function should be in any program
	cout<<"Hello"<<endl; // Console Output // ostream class // "<< - Insertion Operator"
	int a=10;
	cout<<"The valuve of a is "<<a<<endl; // Format Specifiers are not required to be specified in C++
	int b;
	cin>>b; // Console Input belongs to istream class
	cout<<"The value of b is "<<b; // Like we use printf("b= %d",b); in c language
}
