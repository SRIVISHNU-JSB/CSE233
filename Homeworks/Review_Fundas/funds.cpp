#include<iostream>
using namespace std;

int main()
{
    int s[5];
    cout<<"Enter the values: ";
    cin>>s[0]>>s[1]>>s[2]>>s[3];
    for (int i=0;i<5;i++)
    {
        cout<<s[i]<<"\xF8"<<endl;
    }
}

