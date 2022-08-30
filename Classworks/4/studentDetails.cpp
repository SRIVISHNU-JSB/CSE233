#include<iostream>
using namespace std;

struct Student
	{
		int age;
		char first_name[50];
		char last_name[50];
		int standard;
	};

int main(){
	struct Student s1;
	cout<<"Age: ";
	cin>>s1.age;
	cout<<"First Name: ";
	cin>>s1.first_name;
	cout<<"Last Name: ";
	cin>>s1.last_name;
	cout<<"Standard: ";
	cin>>s1.standard;
	
	cout<<s1.age<<" "<<s1.first_name<<" "<<s1.last_name<<" "<<s1.standard;
}
