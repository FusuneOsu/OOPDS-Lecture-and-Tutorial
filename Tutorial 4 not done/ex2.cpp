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

public:
    Student()
    {
        id = 0;
        name = "X";
        age = -1;
    }
    Student(int id, const string &name, int age)
        : id(id), name(name), age(age) {}
    int getId() const { return id; }
    void setId(int id) { Student::id = id; }
    const string &getName() const { return name; }
    void setName(const string &name) { Student::name = name; }
    int getAge() const { return age; }
    void setAge(int age) { Student::age = age; }
};
class Subject
{
private:
    int size;
    unique_ptr<Student[]> subjList;
    void fill()
    {
        this->size = size;
        subjList = make_unique<Student[]>(size);
        for (int i = 0; i < size; i++)
        {
            subjList[i].setId(rand() % 10 + 1);
            char ch = rand() % 26 + 65;
            string s = s + ch;
            subjList[i].setName(s);
            subjList[i].setAge(rand() % 25 + 1);
        }
    }

public:
    Subject()
    {
        size = 5;
        fill();
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
    // (2) Add a parametrized constructor to the class Subject that will receive
    // an int size and creates an array of Students of size (size) using the
    // fill method.
    // (3) Add a display method to the class Subject to display the elements of
    // the array subjList.
    // (4) Add a method to the class Subject to sort the array subjList in
    // ascending order based on student’s age.
    // (5) Add a method to the class Subject to search the array subjList for a
    // given student id. The method should list all the students with the same
    // id equal to id.
    // (6) Add destructors to the above two classes to display messages that
    // objects were destroyed.
    // (7) Add messages to the constructors of both classes displaying that the
    // objects were created.
    // (8) Study the sequence of creation and destruction of objects.
    // (9) Is there any memory leak in this example?
    
    return 0;
}