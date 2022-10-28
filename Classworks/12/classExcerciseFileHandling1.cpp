/*
WAP to count the number of blank spaces present in a text file out.txt
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	string s1;
	s1 = "This is an introduction to C++    so its very easy."
	fstream f2;
	f2.open("out.txt",ios::out);
	f2<<s1;
	f2.close();
	
	f2.open("out.txt",ios::out);
	if(f1.is_open())
	{
		while(!f1.eof())
		{
			f1>>c;
			cout<<c;
			if(c==" ")
			{
				int a;
				a = a +1;
			}
			
		}
	}
	else
	{
		cout<<"File does not exist!";
	}
	f1.close();
}
