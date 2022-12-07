#include "Student.hpp"

void Student::print() { cout << id << endl; }

void Student::setID(int d) { id = d; }

void Student::setName(string str) { name = str; }

int Student::getID() { return id; }

string Student::getName() { return name; }

void Student::setStudent(int d, string s) {
  id = d;
  name = s;
}

void Student::show() {
  print();
  cout << name << endl;
}