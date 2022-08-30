// static memmber functions consists only static variables

// Write a program to count the total number of admissions in a university. Use static data member.


#include<iostream>
using namespace std;

class Admission{
	int n;
	static int no_of_students;
	public:
	void new_student(){
		cout<<"How many New students: ";
		cin>>n;
		no_of_students+=n;
	}
	static void total_students(){
		cout<<"Total Students: "<<no_of_students<<endl;
	}
};

int Admission::no_of_students;

int main(){
	Admission s1,s2,s3,s4;
	s1.new_student();
	s2.new_student();
	s3.new_student();
	s4.new_student();
	Admission::total_students();
}
