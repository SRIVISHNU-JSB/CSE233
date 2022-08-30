#include<iostream>
using namespace std;
// WAP to swap two numbers, create a function swap() whith its return type int with two parameters(int,int).

//Call by Value
//Call by Reference

int main()
{
    int a,b;
    cout<<"Enter two number:"<<endl;
    cin>>a>>b;

    cout<<endl;

    cout<<"Before Swapping:"<<endl;
    cout<<"A: "<<a<<endl;
    cout<<"B: "<<b<<endl;

//  swap(a,b); //actual arguments
    swap(a,b); //actual arguments


    cout<<"After Swapping:"<<endl;
    cout<<"A: "<<a<<endl;
    cout<<"B: "<<b<<endl;
}

//Call by Value
//int swap(int v1,int v2) //formal arguments vs actual arguments
//{
//  cout<<endl;
//  cout<<"Before Swapping:"<<endl;
//  cout<<"v1: "<<v1<<endl;
//  cout<<"v2: "<<v2<<endl;
//
//  int c=v1;
//  v1=v2;
//  v2=c;
//
//  cout<<"After Swapping:"<<endl;
//  cout<<"v1: "<<v1<<endl;
//  cout<<"v2: "<<v2<<endl;
//
//}

//Call by Reference
//int swap(int &v1,int &v2) //formal arguments vs actual arguments
//{
//  cout<<endl;
//  cout<<"Before Swapping:"<<endl;
//  cout<<"v1: "<<v1<<endl;
//  cout<<"v2: "<<v2<<endl;
//
//  int c=v1;
//  v1=v2;
//  v2=c;
//
//  cout<<"After Swapping:"<<endl;
//  cout<<"v1: "<<v1<<endl;
//  cout<<"v2: "<<v2<<endl;
//
//}

//Call by Reference
int swap(int *v1,int *v2) //formal arguments vs actual arguments
{
    cout<<endl;
    
    cout<<"Before Swapping:"<<endl;
    cout<<"*v1: "<<*v1<<endl;
    cout<<"*v2: "<<v2<<endl;

    int c=*v1;
    *v1=*v2;
    *v2=c;
    
    cout<<endl;

    cout<<"After Swapping:"<<endl;
    cout<<"*v1: "<<*v1<<endl;
    cout<<"*v2: "<<*v2<<endl;

}