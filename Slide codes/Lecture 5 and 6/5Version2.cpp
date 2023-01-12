#include <iostream>
using namespace std;

class A{
public:
void print(){
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
A a;
B b;
C c;
a.print();
b.print();
c.print();
return 0;
}