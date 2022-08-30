#include <iostream>

using namespace std;

class Student
{
    int reg_number;
    float marks[3];
public:
    void get()
    {
        int *p; //Defining the pointer
        p=&reg_number; //Initialize the pointer
        cout<<"Enter the registration number: ";
        cin>>*p;
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

    Student s1;
    void (Student::*pf)()=&Student::get;

    (s1.*pf)(); //s1.get();
    s1.print();

    Student *ps1=&s1;

    (ps1->*pf)(); //ps1->get();
    ps1->print();

}