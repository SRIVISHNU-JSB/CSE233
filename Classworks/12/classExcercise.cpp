/*
WAP to create a file "Example" and write "File handling in C++" to that file then
after that read the content from the same file
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	string s1;
	s1 = "File handling in C++";
	ofstream wf;
	wf.open("Example"); //noreplace mode not to replace the file
	wf<<s1;
//	wf<<"File handling in C++";
//	cout<<wf;
	wf.close();
	
//	string s2;
//	ifstream rf;
//	rf.open("Example");
//	rf>>s2;
//	rf.close();
//	cout<<s2;
	ifstream f1("Example");
	string s;
	char c;
	if(f1.is_open())
	{
//		getline(f1,s);
//		cout<<s;
		while(!f1.eof())
		{
			f1>>c;
			cout<<c;
		}
	}
	else
	{
		cout<<"File does not exist!";
	}
	f1.close();
}