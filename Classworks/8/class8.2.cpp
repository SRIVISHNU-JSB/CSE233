#include<iostream>
using namespace std;

// Parameterized and copy contructor

// WAP Create a class car{} with the data members brand, model, year and use constructor overloading and print the details of 2 such cars also copy the brand and year of car1 to car3 and take the model name from the user using copy constructor


class car
{
    // char brand[10];
    char *brand;
    // string brand;
    // string brand="Tesla";
    int year;
    // int year=2022;
    // char model[10];
    char *model;
    // string model;
    // string model="Roadster";
    public:
    car()
    {
        brand = "Tesla";
        year = 2022;
        model = "Roadster";
    }
    car(string brand, int year, string model)
    {
        brand = brand;
        year = year;
        model = model;
    }
    car(car &c)
    {
        brand = c.brand;
        year = c.year;
        cout<<"Enter the model name: ";
        cin>>model;
    }
    void print()
    {
        // brand="Tesla";
        cout<<brand<<year<<model<<endl;
    }
};

int main()
{
    car car1;
    car1.print();
    car car2;
    car2.print();
    car car3(car1);
    car3.print();

    return 0;
}