#include<iostream>
using namespace std;
 
// Defining  an enum
enum GeeksforGeeks { Geek1,
                     Geek2,
                     Geek3 };
 
// GeeksforGeeks G1 = Geek1;
// GeeksforGeeks G2 = Geek2;
// GeeksforGeeks G3 = Geek3;
 
// Driver Code

enum daysOfWeek { Sun, Mon, Tue };
daysOfWeek today, payday;
int main()
{
    // cout<<Geek1<<Geek2<<Geek3;
    // int G1,G2,G3;
    // cout << "The numerical value "
    //      << "assigned to Geek1 : "
    //      << G1 << endl;
 
    // cout << "The numerical value "
    //      << "assigned to Geek2 : "
    //      << G2 << endl;
 
    // cout << "The numerical value "
    //      << "assigned to Geek3 : "
    //      << G3 << endl;

    today = Tue;
    cout<<today;
 
    return 0;
}