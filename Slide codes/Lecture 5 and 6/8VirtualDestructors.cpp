#include <iostream>
using namespace std;

class A{
public:
A() {
cout << "A constructed.." << endl;
}
virtual ~A(){
cout << "A Destroyed.." << endl;
}
};
class B:public A{
public:
B(){
cout << "B constructed.." << endl;
}
~B(){
cout << "B Destroyed.." << endl;
}
};

int main()
{
cout << "...1..." << endl;
A *a = new A();
cout << "...2..." << endl;
delete a;
cout << "...3..." << endl;
A *b = new B();
cout << "...4..." << endl;
delete b;
cout << "...5..." << endl;
return 0;
}

// It's a good idea to make destructors virtual if the class could ever become a
// base class.

// Otherwise, the compiler will perform static binding on the destructor if the class
// ever is derived from.

// without virtual destructor in Base Class A:
// ...1...
// A constructed..
// ...2...
// A Destroyed..
// ...3...
// A constructed..
// B constructed..
// ...4...
// A Destroyed..
// ...5...
// Child object is not destroyed

// with virtual destructor in Base Class A:
// ...1...
// A constructed..
// ...2...
// A Destroyed..
// ...3...
// A constructed..
// B constructed..
// ...4...
// B Destroyed..
// A Destroyed..
// ...5...
// Child object is destroyed