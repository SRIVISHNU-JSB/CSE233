#include<iostream>
using namespace std;

int max(int a, int b)
{
    int max=0;
    max=a>b?a:b;
    return max;
}
int maxOfFour(int a, int b, int c, int d)
{
    int max_of_four=0;
    max_of_four=max(max(max(a,b),c),d);
    return max_of_four;
}

int main()
{
    int a=1000,b=22,c=333,d=44;
    int result=0;
    cout<<result<<endl;
    result=maxOfFour(a,b,c,d);
    cout<<result<<endl;

    return 0;
}