#include <iostream>
using namespace std;

class A final {
public:
void print() {
cout << "I am A" << endl;
}
};

// Class B can no longer be inherited
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

// PAGE 33 <-Sambung slides