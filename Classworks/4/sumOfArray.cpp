#include<iostream>

using namespace std;

int main()
{
	
	int num, sum=0;
	int array[100];
	cout<<"how many numbers you want to enter:";
	cin>>num;
	
	for( int i=0; i<num; i++){
		cout<<"enter number: ";
		cin>>array[i];
	}
	
	for (int j=0; j<num; j++){
		sum+=array[j];
	}
	
	cout<<"Sum: "<<sum;
	
}
