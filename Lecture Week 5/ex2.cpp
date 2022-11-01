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
    cout << "----------------------------\n";
    cout << "ID :" << this->sid << endl << "Name :" << name << endl;
    cout << "Marks: ";
    for (int i = 0; i < 5; i++)
      cout << marks[i] << ":";
    cout << endl;
    cout << "GPA :" << gpa << endl;
    cout << "----------------------------\n";
  }
};

int main() {
    float m[]{90,80,70,60,77};
    Student c[3];     // uses default constructor 

    for (int i=0; i<3; i++)
        c[i].show();


    Student f[]{      // uses param constructor
        {100,"A", m, 3.1f},
        {101,"B", m, 3.1f},
        {103,"C", m, 3.1f},
        {104,"D", m, 3.1f},
        {109,"F", m, 3.1f},
    };

    for (int i=0; i<5; i++)
        f[i].show();

  return 0;
}