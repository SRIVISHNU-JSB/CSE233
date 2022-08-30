#include<iostream>
using namespace std;

int max_of_four(int a, int b, int c, int d);

int main(){
	int a, b, c, d;
	
	cout<<"Enter a: ";
	cin>>a;
	cout<<"Enter b: ";
	cin>>b;
	cout<<"Enter c: ";
	cin>>c;
	cout<<"Enter d: ";
	cin>>d;
	int result = max_of_four(a, b, c, d);
	cout<<"Greatest number is "<<result;
}

int max_of_four(int a, int b, int c, int d)
{
	if (a>b && a>c && a>d){
		return a;
	}
	else if (b>a && b>c && b>d){
		return b;
	}
	else if (c>a && c>b && c>d){
		return c;
	}
	else{
		return d;
	}
}
