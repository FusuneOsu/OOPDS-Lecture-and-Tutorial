#include <iostream>
using namespace std;

class Parent
{
    string label;

public:
    Parent() : label("default") {}
    Parent(string val) : label(val) {}
    string getLabel() { return label; }
    void print()
    {
        cout << "Parent ...\n";
    }
};

// Redefining methods: methods in a derived class
// that has the same name and parameter list as a
// method in the base class

// Used to replace a method in base class with
// different actions in derived class

// Not the same as overloading – with overloading,
// parameter lists must be different and exists in the
// same class

// Objects of base class use base class version of
// the method

// Objects of derived class use derived class
// version of method

// 1. Normal child class definition
// class Child : public Parent
// {
// public:
//     Child() : Parent() {}
//     Child(string v) : Parent(v) {}
//     void print()
//     {
//         cout << "Child ..." << endl;
//     }
// };

// 2.Redefined child class to inherit function from parent base class
class Child : public Parent
{
public:
    Child() : Parent() {}
    Child(string v) : Parent(v) {}
};

int main()
{
    Parent p("Superman");
    Child c("Hulk");
    p.print();
    c.print();
    return 0;
}