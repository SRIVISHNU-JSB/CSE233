#include <iostream>

using namespace std;

class Student
{
    int reg_number;
    float marks;
public:
    void get()
    {
        int *p; //Defining the pointer
        p=&reg_number; //Initialize the pointer
        cout<<"Enter the registration number: ";
        // cin>>*p;
        cout<<"Enter the marks: ";
        cin>>marks;
    }
    
    void print()
    {
        cout<<"The registration number: "<<reg_number<<endl;
        cout<<"The marks: ";
        cout<<marks<<endl;
    }
};

int main()
{

    Student s;
    Student *ps;
    ps=&s;

    s.get();
    // s.print();
    cout<<"\nPointer\n";
    // (*ps).print();
    ps->get(); //*ps.get()
    ps->print(); //*ps.print()

}