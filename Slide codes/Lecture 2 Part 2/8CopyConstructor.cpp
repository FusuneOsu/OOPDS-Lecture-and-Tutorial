// Copy constructor:
// Special constructor
// used when a newly
// created object is
// initialized to the data of
// another object of same
// class

#include <iostream>
using namespace std;

class Car
{
private:
    string *name;
    int *engsize;
    int passengers;

public:
    Car();
    Car(string s, int, int); //shallow copy
    Car (const Car &); //deep copy
    void setName(string n);
    void setEngSize(int size);
    void setPass(int);
    void print();
};

Car::Car() //Default constructor I guess
{
name = new string("Proton Preve");
engsize = new int(1600);
passengers = 5;
}

// Car::Car(string n, int sz, int pss) //Copy constructor, shallow copy
// {
// name = new string(n);
// engsize = new int(sz);
// passengers = pss;
// }

Car::Car(const Car &c) { //Deep copy constructor
name = new string;
*name = *(c.name);
engsize = new int;
*engsize = *(c.engsize);
passengers = c.passengers;
}
// Since copy constructor has a
// reference to the object it is
// copying from, it can modify that
// object.

// To prevent this from happening,
// make the object parameter const

// Copy constructor is a constructor with 
// a const reference to an object of the same
// type passed as a parameter.

void Car::setName(string s)
{
*name = s;
}
void Car::setEngSize(int size)
{
*engsize = size;
}
void Car::setPass(int pass)
{
passengers = pass; 
}

void Car::print()
{
cout << *name << endl
     << *engsize
     << endl
     << passengers
     << endl;
}

int main()
{
Car c1;
c1.print();
Car c2(c1);
c2.print();
c2.setName("Alza");
c2.setEngSize(1500);
c2.setPass(7);
c2.print();
c1.print();
return 0;
}