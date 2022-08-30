// Write a program to count the total number of admissions in a university. Use static data member.


#include<iostream>
using namespace std;

class Admission{
	static int no_of_students;
	public:
};
void new_student(){
	no_of_students+=1;
	cout<<"Total Students: "<<no_of_students<<endl;
}

int Admission::no_of_students;

int main(){
	Admission s1,s2,s3,s4;
	s1.new_student();
	s2.new_student();
	s3.new_student();
	s4.new_student();
}
