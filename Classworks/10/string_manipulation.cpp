#include<iostream>
#include<string>
using namespace std;
//String manipulation string.insert(), string.erase(), string.replace(), string.append()

int main()
{
	string s1,s2,s3;
	s1="An introduction to objected oriented programming...";
	s1.insert(12,"cat");
	cout<<s1;
}