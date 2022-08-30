#include<iostream>
using namespace std;

class Student{
	private:        // by default all are private
	int reg_number;
	char grade;
	float cgpa;
	public:
	void getdata(){   // inline function
		cout<<"Enter the Registration number: ";
		cin>>reg_number;
		cout<<"Enter the grade: ";
		cin>>grade;
		cout<<"Enter the cgpa: ";
		cin>>cgpa;
	}
	public:
	void putdata(){
		cout<<"\nRegistration number: "<<reg_number;
		cout<<"\nGrade: "<<grade;
		cout<<"\nCGPA: "<<cgpa;
	}
};

// if function is defined outside

//void Student::putdata(){
//	cout<<"\nRegistration number: "<<reg_number;
//	cout<<"\nGrade: "<<grade;
//	cout<<"\nCGPA: "<<cgpa;
//}

int main(){
	Student s1;
	s1.getdata();
	s1.putdata();
}
