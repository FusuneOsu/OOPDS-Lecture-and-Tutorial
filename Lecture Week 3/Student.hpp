#include <iostream>
using namespace std;

class Student {
  int id;
  string name;
  void print();

public:
  void setID(int);
  void setName(string);
  int getID();
  string getName();
  void show();
  void setStudent(int, string);
};