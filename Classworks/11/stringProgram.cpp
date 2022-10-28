/* WAP to take a string input from the user and store it in a class data member s_value
create a member function of the class void print() to print a substring starting from the index postion (3,10) upto index postion 10
also find the occurence of character i in the given string
create another function void perform() that will append $ 5 times in the given string
*/ 
#include<iostream>
using namespace std;

class getString
{
	string s_value;
	
	public:
		
		void get(){
			getline(cin,s_value);
		}
		
		void print(){
			
			s_value.substr(2,10);
			cout<<s_value<<endl;
		}
		void perform(){
			s_value.insert(4,"#####");
		}
};


int main()
{
	getString s1;
	s1.get();
	s1.print();
	s1.perform();
	s1.print();
}