#include <iostream>
#include <ostream>
#include "Student.hpp"

using namespace std;

void print( Student *q){
    cout << q->getName() << ":" << q->getID() << endl;
}

int main(){

    Student s;
    s.setStudent(99, "sharaf");

    Student *ptr;      // ptr is a pointer to a student object
    ptr = &s;          // ptr points to the address of s

    cout << (*ptr).getID() << endl
         << (*ptr).getName() << endl;

    cout << ptr->getName() << endl
         << ptr->getID() << endl;

    print(&s);   // pass the address of s to the function print

}