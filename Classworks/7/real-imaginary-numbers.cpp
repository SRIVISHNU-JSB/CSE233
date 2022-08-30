//Create a class Complex with 2 data members with (real, imaginary) integers, 2 member functions void getdata() and void setdata(int, int)
//Create a pointer to Complex class and print the values in the form of (real + i imaginary)
//Create a pointer to member function setdata(int, int)
//Call getdata using objects and call setdata using pointer to object with function pointer.

#include<iostream>
using namespace std;

class Complex
{
    int real;
    int imaginary;
    public:
    void getdata()
    {
        // int *p1,*p2;
        // *p1 = &real;
        // *p2 = &imaginary;
        cout<<"Entered real and imaginary numbers: ";
        // cin>>*p1>>*p2;
    }

    void setdata(int i, int j)
    {
        real = i;
        imaginary = j;
    }

    void printdata()
    {
        int *p1;
        int *p2;
        // *p1 = &real;
        // *p2 = &imaginary;
        // cout<<*p1<<"+ i "<<*p2;
        cout<<real<<" + i "<<imaginary;
    }
};

int main()
{
    Complex c;
    Complex *cs;
    cs=&c;
    cs->getdata();
    cs->setdata(5, 8);
    cs->printdata();

    Complex c1;
    void (Complex::cf)(int, int)=&Complex::setdata;
    
    


}