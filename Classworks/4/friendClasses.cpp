#include<iostream>
using namespace std;

class test1{
	int a, b;
	public:
	void getdata(){
		cout<<"Enter value of a and b: ";
		cin>>a>>b;
	}
	friend class test2;
};

class test2{
	public:
	void putdata(test1 ob){
		cout<<"a = "<<ob.a;
		cout<<"\nb = "<<ob.b;
	}
};

main(){
	class test1 obj1;
	class test2 obj2;
	obj1.getdata();
	obj2.putdata(obj1);
}
