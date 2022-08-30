// Create a class with name student. Take value of rollno, name through friend function and print those values through member function.

#include<iostream>
using namespace std;

class student{
	int rollno;
	char name[30];
	
	public:
	friend void getDetails(student);
	void printDetails(){
		cout<<"Roll no: "<<rollno;
		cout<<"\nName: "<<name;
	}
	
};
void getDetails(student obj){
	cout<<"Enter roll no.: ";
	cin>>obj.rollno;
	cout<<"Enter name: ";
	cin>>obj.name;
}

main(){
	student ob;
	getDetails(ob);
	ob.printDetails();
}
