//WAP to reverse a string
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	string a = "Hello";
	string reversed_a;
	for(int i=a.length()-1;i>=0;i--)
	{
		cout<<a[i];
	}
}