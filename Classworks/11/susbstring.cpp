#include<iostream>
using namespace std;

int main()
{
	string s1 = "Lovely University";
//	string s1 = "We are studying c++";
	cout<<s1.substr(0,6)<<endl;
	cout<<s1.substr(2,7)<<endl;
	cout<<s1.substr(2)<<endl;
	cout<<s1.size()<<endl;
	cout<<s1.length()<<endl;
	cout<<s1.capacity()<<endl;//Storage size allocated to the string s1
	
	cout<<s1.max_size();
}