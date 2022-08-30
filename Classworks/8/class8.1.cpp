#include<iostream>
using namespace std;

//WAP - Create a class section_detail with data member as section and cgpa, create a constructor which will initialize the section=E2105 and CGPA = 0.0 create a function void get() which will ask the CGPA of the student and student can change the section if the student is not from the section and create a fucntion void print() which will print the section and CGPA of the student


class section_detail
{
    // char section[10]; 
    char section;
    float cgpa;
    public:
    section_detail()
    {
        // section = "E2105";
        // section = "E";N
        cgpa = 0.0f;
    }

    void get()
    {
        // char *response;
        // string response;
        char response;
        cout<<"Your section is: "<<section<<"Do you want to change your section: Y or N"<<endl;
        cin>>response;
        // if(response == 'Y')
        // {
        //     cout<<"Enter your section: "<<endl;
        //     cin>>section;
        // }
        cout<<"Enter your CGPA: "<<endl;
        cin>>cgpa;
    }
    void print()
    {
        cout<<"Student's section is: "<<section<<endl;
        cout<<"Student's CGPA Is: "<<cgpa<<endl;
    }
};

int main()
{
    section_detail obj;
    obj.get();
    obj.print();

    return 0;
}