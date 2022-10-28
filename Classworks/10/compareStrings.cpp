#include<iostream>
//#include<string.h>
using namespace std;

// CPP code perform relational
// operation using compare function
#include <iostream>

using namespace std;

void compareStrings(string s1, string s2)
{
 // comparing both using inbuilt function
 int x = s1.compare(s2);

 if (x != 0) {
  cout << s1
   << " is not equal to "
   << s2 << endl;
  if (x > 0)
   cout << s1
    << " is greater than "
    << s2 << endl;
  else
   cout << s2
    << " is greater than "
    << s1 << endl;
 }
 else
  cout << s1 << " is equal to " << s2 << endl;
}

// Driver Code
int main()
{
 string s1("Geeks");
 string s2("forGeeks");
 compareStrings(s1, s2);
 string s3("Geeks");
 string s4("Geeks");
 compareStrings(s3, s4);
 return 0;
}


//int main()
//{
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	
//	int result = s1.compare(s2);
//	
//	cout<<result;
//	
//	
//	string s1,s2;
//	s1 = "MY";
//	s2 = "MZ";
//	
////	cout<<"Enter two string s1, s2:"<<endl;
////	cin>>s1>>s2;
//	
//	if(s1 == s2)
//	{
//		cout<<"Equal";
//	}
//	else if(s1 < s2)
//	{
//		cout<<"s1 is less than s2";
//	}
//	else if(s1 > s2)
//	{
//		cout<<"s1 is greater than s2";
//	}
//	
//	return 0;
//
//}