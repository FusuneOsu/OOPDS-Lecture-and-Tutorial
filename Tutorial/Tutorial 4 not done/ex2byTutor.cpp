#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
using namespace std;

class Student {
private:
  int id;
  string name;
  int age;

public:
  Student() {
    id = 0;
    name = "X";
    age = -1;
  }
  Student(int id, const string &name, int age) : id(id), name(name), age(age) {}
  int getId() const { return id; }
  void setId(int id) { this->id = id; }
  string getName() const { return name; }
  void setName(const string &name) { this->name = name; }
  int getAge() const { return age; }
  void setAge(int age) { this->age = age; }
};

class Subject {
private:
  int size;
  Student *subjList;

  void fill() {
    for (int i = 0; i < size; i++) {
      subjList[i].setId(rand() % 10 + 1);
      char ch = rand() % 26 + 65;
      string s = to_string(ch);
      subjList[i].setName(s);
      subjList[i].setAge(rand() % 25 + 1);
    }
  }

public:
  Subject(int size = 5) {
    this->size = size;
    subjList = new Student[size];
    fill();
  }

  void sortAge() {

    for (int i = 0; i < size - 1; i++) {
      for (int j = i; j < size; j++) {
        if (subjList[i].getAge() > subjList[j].getAge()) {
          int age = subjList[i].getAge();
          string name = subjList[i].getName();
          int id = subjList[i].getId();

          subjList[i].setId(subjList[j].getId());
          subjList[i].setAge(subjList[j].getAge());
          subjList[i].setName(subjList[j].getName());

          subjList[j].setId(id);
          subjList[j].setAge(age);
          subjList[j].setName(name);
        }
      }
    }
  }

  void search(int id) {
    for (int j = 0; j < size; j++) {
      if (id == subjList[j].getId()) {
        cout << subjList[j].getId() << ":" 
             << subjList[j].getName() << ":"
             << subjList[j].getAge() << endl;
      }
    }
  }

  void display(){
    for (int j = 0; j < size; j++) {
        cout << subjList[j].getId() << ":" 
             << subjList[j].getName() << ":"
             << subjList[j].getAge() << endl;
    }
  }

  ~Subject() {
    if (subjList != nullptr)
      delete[] subjList;
  }
};
int main() {
  srand(time(0));

  Subject tcp1201;

  tcp1201.sortAge();

  tcp1201.display();
  
  cout << "------------- \n";
  
  Subject tcp1202(10);
  
  tcp1202.sortAge();
  
  tcp1202.display();
  
  cout << "------------- \n";
  
  int id;
  cout << "Enter an id: ";
  cin >> id;
  tcp1202.search(id);
  return 0;
}