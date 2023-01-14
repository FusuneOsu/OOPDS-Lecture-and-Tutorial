#include <iostream>
using namespace std;

class Parent{
string label;
public:
Parent():label("default"){}
Parent(string val):label(val){}
string getLabel(){return label;}
// Class Parent defines functions printX()
// and printY(). PrintX() calls printY().
void printY(){
cout << "Parent A..." << endl;
}
void printX(){
printY();
cout << "Parent B..." << endl;
}
};

class Child: public Parent{
public:
// Class Child inherits from Parent and
// redefines method printY().
Child():Parent(){ }
Child(string v):Parent(v){ }
void printY(){
cout << "Child A..." << endl;
}
};

int main() {
// An object child of class Child is created
// and method printX() is called.
Child child("Hulk");
child.printX();
// When printX() is called, which y() is
// used, the one defined in Parent or the
// the redefined one in Child?
return 0;
}