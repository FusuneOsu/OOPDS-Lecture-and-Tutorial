#include <iostream>

using namespace std;

class Human
{
    string name;
    string birthDate;

public:
    Human() { cout << "Human created...\n"; }
    ~Human() { cout << "Human destroyed...\n"; }
};
class Student : public Human
{
    string sid;
    string school;
    int grade;

public:
    Student() { cout << "Student created...\n"; }
    ~Student() { cout << "Student destroyed...\n"; }
};
class Worker : public Human
{
    string wid;

public:
    Worker() { cout << "Worker created...\n"; }
    ~Worker() { cout << "Worker destroyed...\n"; }
};

// int main()
// {
//     cout << "------1--------\n";
//     Human h;
//     cout << "------2--------\n";
//     Student s;
//     cout << "------3--------\n";
//     Worker w;
//     cout << "------4--------\n";
//     return 0;
// }

int main()
{
    cout << "------1--------\n";
    Human *h;
    h = new Human;
    cout << "------2--------\n";
    Student *s;
    s = new Student;
    cout << "------3--------\n";
    Worker *w;
    w = new Worker;
    cout << "------4--------\n";
    return 0;
}