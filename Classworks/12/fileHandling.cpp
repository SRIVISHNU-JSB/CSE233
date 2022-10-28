#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int a;
	ifstream rf;
	rf.open("Text1");
	rf>>a;
	rf.close();
	cout<<a;
}