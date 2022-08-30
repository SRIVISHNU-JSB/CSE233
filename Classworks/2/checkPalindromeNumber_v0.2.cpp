#include<iostream>
using namespace std;

int main()
{
	int num;
	cout<<"Enter a positive number: ";
	cin>>num;
	int n=num;
	int t, rev=0;
	
	while(num>0)
	{
		t=num%10;
		rev=(rev*10)+t;
		num=num/10;
	}
	
	if(n==rev)
	{
		cout<<"Palindrome";
	}
	else
	{
		cout<<"Not a Palindrome";
	}
}

