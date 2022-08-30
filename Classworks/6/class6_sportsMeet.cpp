//WAP - The company xyz is conducting a yearly sports meet for its empoloyees. The interested employees can register by providing
//Name,EmployeeID,YearsOfExperience in that particular company. Total 10 employees have participated, print the details of all
//the 10 employees with the counter as ID allocated to each employee as they have registered.

//Revise the Functions and Pointers topics

#include<iostream>
using namespace std;

//Class are like a datatype - Indeed the user defined data types
class sports
{
    
    char employeeName[50];
    int employeeID;
    int yearsOfExperience;
    static int uniqueID;
    int enrollmentID;
    
    public:
    void get()
    {
        uniqueID++;
        enrollmentID=uniqueID;
        cout<<"Enter Employee Name: ";
        cin>>employeeName;
        cout<<"Enter Employee ID:";
        cin>>employeeID;
        cout<<"Enter the Years of Experience:";
        cin>>yearsOfExperience;

    }

    void print()
    {
        cout<<"Enrollment ID: "<<enrollmentID<<endl;
        cout<<"Employee Name: "<<employeeName<<endl;
        cout<<"Employee ID: "<<employeeID<<endl;
        cout<<"Years of Experience: "<<yearsOfExperience<<endl;
    }

};
int sports::uniqueID=100;

int main()
{
    int n;
    cout<<"Number of Employees: ";
    cin>>n;
    sports p[n];
    int i;
    
    for(i=0;i<n;i++)
    {
        p[i].get();
    }

    cout<<"\nThe details of registered employees are:\n";
    
    for(i=0;i<n;i++)
    {
        p[i].print();
    }
}