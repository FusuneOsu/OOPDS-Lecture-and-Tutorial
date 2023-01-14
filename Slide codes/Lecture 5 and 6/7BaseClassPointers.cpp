#include <iostream>
using namespace std;

class A{
public:
virtual void print() const{
cout << "A.." << endl;
}
};
class B:public A{
public:
virtual void print() const{
cout << "B.." << endl;
}
};
class C:public B{
public:
void print() const {
cout << "C.." << endl;
}
};

int main()
{

// Can define a pointer to a base class object
A *ab = new B();
ab->print();
A *ac = new C();
ac->print();
B *bc = new C();
bc->print();

// Can assign it the address of a derived class object
A *ptrb,*ptrc;
B b;
C c;
ptrb = &b;
ptrb->print();
ptrc = &c;
ptrc->print();
return 0;
}

// Base class pointers and references only know about members of the base class
// So, you can’t use a base class pointer to call a derived class method

// Redefined methods in derived class will be ignored unless base class declares the
// method virtual

// In C++, redefined functions are statically bound and overridden functions are
// dynamically bound.

// So, a virtual function is overridden, and a non-virtual function is redefined.