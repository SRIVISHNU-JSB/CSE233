/*
WAP to Create a file "length.txt" & calculate the length of the file using the pointer functions.
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	string s1;
	fstream f1;
	f1.open("length.txt");
	f1<<"We are learning File Handling in C++";
	f1.close();
	f1.open("lenght.txt",ios::in);
	getline(f1,s1);
	cout<<s1;
//	cout<<f1.get();
}