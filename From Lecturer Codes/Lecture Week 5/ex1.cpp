#include <iostream>
using namespace std;

class Student {
private:
  int sid;
  string name;
  float marks[5];
  float gpa;

public:
  Student() {
    cout << "Default constructor\n";
    sid = 0;
    name = "Default";
    for (int i = 0; i < 5; i++)
      marks[i] = 0;
    gpa = 0;
  }

  Student(int sid, string nm, float marks[], float gpa) {
    cout << "Param constructor\n";
    this->sid = sid;    // this is a must (same variable names)
    this->name = nm;    // this is optional (different names)
    for (int i = 0; i < 5; i++)
      this->marks[i] = marks[i];
    this->gpa = gpa;
  }

  ~Student(){
    cout << "Destructor is invoked\n";
  }

  void show() {
    cout << "ID :" << this->sid << endl << "Name :" << name << endl;
    cout << "Marks: ";
    for (int i = 0; i < 5; i++)
      cout << marks[i] << ":";
    cout << endl;
    cout << "GPA :" << gpa << endl;
  }
};

void fun(){
    Student r;
}

int main() {
  Student s; // uses the default constructor
             // to create s
  s.show();

  cout << "before the block\n";
  {
    Student t;
    Student n;
  }
  cout << "Out of nested scope\n";

  fun();
  cout << "After function call\n";

  float m[]{90.0f, 80.0f, 70.0f, 90.0f, 86.0f};
  string name = "Goh";

  // st is created using the param constructor
  // passing the id->10, name->Goh, m as the grades
  // and gpa->3.6f
  Student st(10, name, m, 3.6f);
  st.show();

  return 0;
}