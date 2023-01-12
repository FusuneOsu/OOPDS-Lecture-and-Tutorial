#include <iostream>
using namespace std;

class A{
public:
A(){
cout << "A Const" << endl;
}
~A(){
cout << "A destr" << endl;
}
};
class B:public A{
public:
B(){
cout << "B Const" << endl;
}
~B(){
cout << "B destr" << endl;
}
};
class C:public B{
public:
C(){
cout << "C Const" << endl;
}
~C(){
cout << "C Destr" << endl;
}
};

int main()
{
cout << "-------1------" << endl;
A a;
cout << "-------2------" << endl;
B b;
cout << "-------3------" << endl;
C c;
cout << "-------4------" << endl;
return 0;
}