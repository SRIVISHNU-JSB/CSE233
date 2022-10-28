#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int x;
	cout<<"Enter any integer:";
	cin>>x;
	ofstream wf;
	wf.open("Text1");
	wf<<x;
//	cout<<wf;
	wf.close();
}