#include <iostream>

using namespace std;
//int main(int argc, char *argv[]) {
//	
//}

int main()
{
	// int number=20;
	int number=20;
	// int *p; //wild pointer
	int *p; //wild pointer
	p=&number;
	
	cout<<number<<endl; //20
	cout<<&number<<endl;
	cout<<p<<endl;
	cout<<&p<<endl; //reference the address pointer variable 
	cout<<*p<<endl; //20 //dereference the value stored in pointer variable
	
}