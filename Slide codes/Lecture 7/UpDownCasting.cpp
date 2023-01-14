#include <iostream>
using namespace std;

class Animal {
public:
void talk() {
cout << "Animal sound ...\n";
}
void walk() {
cout << "Animal walk\n";
}
void sleep() {
cout << "Animal Sleep\n";
}
};

class Cat:public Animal {
public:
void talk() {
cout << "cat hiss..\n";
}
void walk() {
cout << "cat walk..\n";
}
void run() {
cout << "cat run..\n";
}
};

class Dog:public Animal {
public:
void talk() {
cout << "dog bark..\n";
}
void walk() {
cout << "dog walk..\n";
}
void run() {
cout << "Dog run..\n";
}
};

class Poodle:public Dog {
public:
void talk() {
cout << "poodle bark..\n";
}
void walk() {
cout << "poodle walk..\n";
}
};

// Upcasting is a process of treating a pointer or a reference of derived class object as a
// base class pointer and performed automatically.
// auto main() -> int
// {
// Cat c;
// Animal *aptr = &c; //Upcasting
// aptr->talk();
// aptr->walk();
// // aptr->run();
// }

// Downcasting is converting base class pointer (or reference) to derived class pointer
// and must be explicitly done by programmer.
auto main() -> int
{
Cat c;
Animal *aptr = &c;
// aptr->run();
// Cat *cptr = aptr;
Cat *cptr = static_cast<Cat *>(aptr); //downcasting
cptr->talk();
cptr->walk();
cptr->run();
}