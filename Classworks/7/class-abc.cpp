#include<iostream>
using namespace std;

class abc
{
    int a;
    int b;
    public:
    void set(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void get()
    {
        cout<<a<<"\t"<<b<<endl;
    }
};

int main()
{
    abc ob;
    ob.set(10,5);
    ob.get();
}