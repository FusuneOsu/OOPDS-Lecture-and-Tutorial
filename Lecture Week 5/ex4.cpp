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
    Student *ptr;

    ptr = new Student[3];   // uses default constructor


    delete[] ptr;          // must delete dynamic array of object to
                           // invoke the destructor
                           // delete[] will delete the array
                           // delete ptr; will only delete the first
                           // element of the array
    
    return 0;
}