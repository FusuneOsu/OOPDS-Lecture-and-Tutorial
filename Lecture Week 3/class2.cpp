#include <iostream>
#include "Student.hpp"

using namespace std;

void printStudent(Student s) {
  cout << s.getID() << "..." << s.getName() << endl;
}

int main() {
  Student s1;
  s1.setID(20);         // s1.id = 20;
  s1.setName("sharaf"); // s1.name = "sharaf";

  // s1.print();     // it is a private member of the class

  s1.show();

  Student s2;
  s2.setStudent(99, "Ahmad");

  // cout << s1.name << ":" << s1.id << endl;
  cout << s1.getName() << ":" << s1.getID() << endl;

  printStudent(s2);

  return 0;
}