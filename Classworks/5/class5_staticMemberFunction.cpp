#include <iostream>
using namespace std;

// Static Member Function
// Static data member and static member function

// class abc
// {
//     int a;
//     static int b;
// };
//int abc::b; // To initialize the value for b=10 variable otherwise by default it gets assigned zero(0)

class team
{
    private:
    int playerScore;
    static int teamScore;
    public:
    void getData()
    {
        cin>>playerScore;
        teamScore=teamScore+playerScore;
        cout<<"Player Score: "<<playerScore<<endl;
    }
    
    void putData(); // Non member function
    
    static void print()
    {
        // cout<<"Player Score: "<<playerScore<<endl;
        cout<<"Team Score: "<<teamScore<<endl;
    }
};
void team::putData()
{
    cout<<"Player Score: "<<playerScore;
}
int team::teamScore=20;
int main()
{
    team t1,t2,t3,t4,t5;
    t1.getData();
    t2.getData();

}
