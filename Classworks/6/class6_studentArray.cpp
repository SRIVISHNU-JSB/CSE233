#include <iostream>

using namespace std;

class student
{
    int reg;
    float marks[3];
public:
    void get()
    {
        cout<<"Enter the registration number: ";
        cin>>reg;
        cout<<"Enter the marks of 3 subjects: ";
        
        int i;
        
        for(i=0;i<3;i++)
            cin>>marks[i];
    }
    
    void print()
    {
        cout<<"The registration number: "<<reg<<endl;
        cout<<"The marks of 3 subjects: ";
        int i;
        for(i=0;i<3;i++)
            cout<<marks[i]<<endl;
    }
};

int main()
{
    int n;
    cout<<"Enter the number of students: ";
    cin>>n;

    student s[n];
    int i;
    
    for(i=0;i<n;i++)
        s[i].get();
    
    for(i=0;i<n;i++)
        s[i].print();

    // s[3].marks[1];
}