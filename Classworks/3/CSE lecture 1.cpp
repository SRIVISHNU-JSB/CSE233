#include<iostream>
using namespace std;

int main(){      // only one main function should be used
	cout<<"Hello world\n";   // or we can use endl instead of \n
	// cout<<"Hello world"<<endl;
	
	int a = 10;
	cout<<"a = "<<a<<endl;    // cout from class ostream, << insertion operator
	
	int b;
	cout<<"b = ";
	cin>>b;        // cin from istream, >> extraction operator
	cout<<"a + b = ";
	cout<<a+b;
}
