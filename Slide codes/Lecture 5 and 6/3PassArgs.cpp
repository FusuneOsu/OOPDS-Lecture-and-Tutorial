#include <iostream>
using namespace std;

class Parent
{
    string label;

public:
    Parent()
    {
        label = "default";
        cout << label
             << "is created\n";
    }
    Parent(string val)
    {
        label = val;
        cout << label
             << "is created\n";
    }
    string getLabel()
    {
        return label;
    }
    ~Parent()
    {
        cout << label
             << " destroyed \n";
    }
};

class Child : public Parent
{
public:
    Child()
    {
        cout << "Child()"
             << endl;
    }

    // In a derived class, some
    // constructors can be inherited
    // from the base class.

    // The constructors that cannot
    // be inherited are:
    // 1.the default constructor
    // 2.the copy constructor
    // 3.the move constructor
    Child(string v) : Parent(v)
    {
        cout << "Child(string)"
             << endl;
    }
    ~Child()
    {
        cout << getLabel()
             << " destroyed"
             << endl;
    }
};

// Lazier Child class alternative:
// class Child : public Parent
// {
// public:
//     using Parent::Parent;
//     ~Child()
//     {
//         cout << getLabel()
//              << " destroyed"
//              << endl;
//     }
// };

int main()
{
    Child c("Superman");
    return 0;
}