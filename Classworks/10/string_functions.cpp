#include<iostream>
#include<string>

int main()
{
	string s1,s2,s3;
	s1="We are studying c++.";
	s2="It is an object oriented programming language. ";
	
	
	cout<<s1.at(5)<<endl;
	cout<<s1.find_first_of('e')<<endl;
	cout<<s1.find_last_of('e')<<endl;
	cout<<s1.find("are");
}