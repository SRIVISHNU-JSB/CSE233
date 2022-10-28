/*
WAP to create a file "Example" and write "File handling in C++" to that file then
after that read the content from the same file
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	fstream f1;
	f1.open("Notes.txt",ios::out);
	
	for (int i=1;i<=100;i++)
	{
		f1<<i;
	}
	
	if(f1.is_open())
	{
		while(!f1.eof())
		{
			int a; f1>>a;
			cout<<a;
		}
	}	
	
	f1.close();
	
}