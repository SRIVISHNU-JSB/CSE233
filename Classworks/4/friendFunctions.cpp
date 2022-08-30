// Friend function: A function which is declared inside the class but is a non-member funciton
// to access the private variables with friend keyword

#include<iostream>
using namespace std;

class A{
	int a;
	int b;
	friend void add(A);  //prototype
};

void add(A obj){
	obj.a = 10;
	obj.b = 20;
	cout<<"Sum = "<<obj.a+obj.b;
}

main(){
	A ob;
	add(ob);
}
