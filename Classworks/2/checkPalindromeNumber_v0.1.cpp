#include <iostream>
using namespace std;

int main()
{
     int n, reversed=0, remainder, original;

     cout << "Enter a positive number: ";
     cin >> n;

     original = n;

    //while (n != 0)
    while(numb>0)
     {
        remainder = n % 10;
        reversed = (reversed * 10) + remainder;
        n = n / 10; // n /= 10
     }

     cout << " The reverse of the number is: " << reversed << endl;

     if (original == reversed)
         cout << " The number is a palindrome.";
     else
         cout << " The number is not a palindrome.";

    return 0;
}
