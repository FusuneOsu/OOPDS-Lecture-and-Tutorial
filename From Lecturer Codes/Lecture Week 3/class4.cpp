#include <iostream>
#include <ostream>
#include "Student.hpp"

using namespace std;

void print( Student q[], int size){
    for (int i=0; i<size; i++)
        cout << q[i].getName() << ":" << q[i].getID() << endl;
}

void print(Student &d){
    cout << d.getName() << ":" << d.getID() << endl;
}

int main(){

    Student s[3];

    s[0].setStudent(99, "sharaf");
    s[1].setStudent(100, "Ahmad");
    s[2].setStudent(200, "Afnaan");

    print (s, 3);

    Student &r = s[0];    // r is a lvalue reference  to the first
                          // element in the array (r and s[0] are the same thing)


    r.setID(88);

    print (s, 3);

    print (r);
    print (s[0]);
}