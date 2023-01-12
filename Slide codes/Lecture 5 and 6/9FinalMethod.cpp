#include <iostream>
using namespace std;

//Below implementation is wrong and will cause error
// Fixes
// 1. add virtual keyword in front of print() function in class A
// 2. delete/comment the print() function in class B because the print() function in class A can no longer be inherited
// 3. in the main, it will be new A() to call the print function
// class A{
// public:
// void print() final {
// cout << "I am A" << endl;
// }
// };
// class B:public A {
// public:
// void print(){
// cout << "I am B" << endl;
// }
// };

// int main()
// {
// A *a = new B();
// a->print();
// return 0;
// }

//correct code:
class A{
public:
virtual void print() final {
cout << "I am A" << endl;
}
};
// class B:public A {
// public:
// void print(){
// cout << "I am B" << endl;
// }
// };

int main()
{
A *a = new A();
a->print();
return 0;
}