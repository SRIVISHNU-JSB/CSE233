#include<iostream>
using namespace std;

int main(){
	int num, n, rem, rev = 0;
	
	cout<<"Enter a number: ";
	cin>>num;
	n = num;
	
	while (n != 0){
		rem = n%10;
        rev = rev*10+rem;
        n = n/10;
	}
	
	if (rev == num){
		cout<<num<<" is a palindrome.";
	}
	else{
		cout<<num<<" is not a palindrome.";
	}
}
