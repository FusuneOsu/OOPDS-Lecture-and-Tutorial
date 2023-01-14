#include <iostream>
using namespace std;

class A{
public:
virtual void print(){
cout << "A.." << endl;
}
};
class B:public A{
public:
void print(){
cout << "B.." << endl;
}
};
class C:public B{
public:
void print(){
cout << "C.." << endl;
}
};

int main()
{
// Polymorphic behavior is only possible when an object is referenced by a
// reference variable or a pointer, as demonstrated in the print() method.
A *aa = new A(); aa->print();
A *ab = new B(); ab->print();
A *ac = new C(); ac->print();
B *bb = new B(); bb->print();
B *bc = new C(); bc->print();
C *cc = new C(); cc->print();
return 0;
}

// with virtual keyword in Class A:
// A..
// B..
// C..
// B..
// C..
// C..

// without virtual keyword in Class A:
// A..
// A..
// A..
// B..
// B..
// C..

// with virtual keyword in Class A and Class B:
// A..
// B..
// C..
// B..
// C..
// C..

// with virtual keyword only in Class B:
// A..
// A..
// A..
// B..
// C..
// C..