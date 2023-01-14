#include <iostream>
using namespace std;

class A{
public:
A(){cout << "A const def\n";}
virtual void print () {
cout << "I am A\n";
}
virtual ~A(){cout << "A destr\n";}
};
class B{
public:
B(){cout << "B const def\n";}
virtual void print () {
cout << "I am B\n";
}
virtual ~B(){cout << "B destr\n";}
};

//inheriting from more than one parent class
class C:public B, public A{
public:
C(){cout << "C const def\n";}
void print () {
cout << "I am C\n";
}
~C() {cout << "C destr\n";}
};

int main() {
A *pa = new A();
B *pb = new C();
pa->print();
pb->print();
delete pa;
delete pb;
return 0;
}