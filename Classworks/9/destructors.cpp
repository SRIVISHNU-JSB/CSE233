#include<iostream>
using namespace std;

class Point
{
    int x,y;
    public:
    Point(int i=0, int j=0):x(i),y(j) // List initializer    
    // Point(int i=0, int j=0):x(10),y(123)
    {

        cout<<this<<" Constructor\n";
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    ~Point()
    {
        cout<<this<<" Destructors\n";
    }
};

int main()
{
    // cout<<endl;
    Point p;
    Point p1;
    Point p2;
    cout<<endl;
    cout<<"Hello World"<<endl;
    cout<<endl;

    return 0;
}