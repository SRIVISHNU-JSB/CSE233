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
        cout<<"The marks of 3 subjects:-";
        int i;
        for(i=1;i<=3;i++)
            cout<<"\nSubject "<<i<<": "<<marks[i];
    }
};

int main()
{
    int n;
    cout<<"Enter the Number of students: ";
    cin>>n;
    student s[n];
    for(int i=1;i<=n;i++)
    {
        s[i].get();
    }
    
    for(int i=1;i<=n;i++)
    {
        s[i].print();
    }
}