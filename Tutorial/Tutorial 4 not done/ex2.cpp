#include <iostream>
#include <memory>
#include <ctime>
#include <cstdlib>
using namespace std;

class Student
{
private:
    int id;
    string name;
    int age;

//if we write "new", we need to write destructor
//rule of 5?

public:
    Student()
    {
        id = 0;
        name = "X";
        age = -1;
    }

    Student(int id, const string &name, int age) : id(id), name(name), age(age) {}
    
    int getId() const { return id; }
    void setId(int id) { Student::id = id; }

    string getName() const { return name; }
    //const //by returning a reference to a private member of the class
    //this will make the "name" visible to outside the class scope which breaches information hiding
    void setName(const string &name) { Student::name = name; }
    
    int getAge() const { return age; }
    void setAge(int age) { Student::age = age; }
};
class Subject {
private:
  int size;
  Student *subjList;

  // (2) Add a parametrized constructor to the class Subject that will receive
  // an int size and creates an array of Students of size (size) using the
  // fill method.
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

  // (4) Add a method to the class Subject to sort the array subjList in
  // ascending order based on student’s age.
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

  // (5) Add a method to the class Subject to search the array subjList for a
  // given student id. The method should list all the students with the same
  // id equal to id.
  void search(int id) {
    for (int j = 0; j < size; j++) {
      if (id == subjList[j].getId()) {
        cout << subjList[j].getId() << ":" 
             << subjList[j].getName() << ":"
             << subjList[j].getAge() << endl;
      }
    }
  }

  // (3) Add a display method to the class Subject to display the elements of
    // the array subjList.
  void display(){
    for (int j = 0; j < size; j++) {
        cout << subjList[j].getId() << ":" 
             << subjList[j].getName() << ":"
             << subjList[j].getAge() << endl;
    }
  }

  // (6) Add destructors to the above two classes to display messages that
  // objects were destroyed.
  ~Subject() {
    if (subjList != nullptr)
      delete[] subjList;
  }
};
int main()
{
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

    // (1) Compile the program and study the errors. You are not allowed to alter
    // the main program during this exercise.
    
    // (7) Add messages to the constructors of both classes displaying that the
    // objects were created.
  
    // (8) Study the sequence of creation and destruction of objects.

    // (9) Is there any memory leak in this example
    // -> maybe
    
    return 0;
}