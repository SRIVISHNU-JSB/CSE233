#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter the size of Equilateral Triange:";
	cin>>n;
	
	int i, j;
	
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=i;j++)
		{
			cout<<"*";

		}
		cout<<endl;
	}
}
