#include <iostream>
using namespace std;

// Abstract base class: class that can have no objects. Serves as a basis for derived
// classes that may/will have objects.

// A class becomes an abstract base class when one or more of its member
// functions is a pure virtual function.
class A
{
public:
    virtual void print() = 0;
};
class B : public A
{
public:
    void print()
    {
        cout << "I am B" << endl;
    }
};
class C : public A
{
public:
    void print()
    {
        cout << "I am C" << endl;
    }
};

int main()
{
    A *ab = new B();
    ab->print();
    A *ac = new C();
    ac->print();
    return 0;
}