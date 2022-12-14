#include <iostream>

using namespace std;

class Human
{
    string name;
    string birthDate;

public:
    Human() { cout << "Human created...\n"; }
    ~Human() { cout << "Human destroyed...\n"; }

    void setName(string n)
    {
        name = n;
    }

    void setBirthDate(string bd)
    {
        birthDate = bd;
    }

    string getname()
    {
        return name;
    }

    string getbirthdate()
    {
        return birthDate;
    }
};

class Student : public Human
{
    string sid;
    string school;
    int grade;

public:
    Student() { cout << "Student created...\n"; }
    ~Student() { cout << "Student destroyed...\n"; }

    void setSid(string i)
    {
        sid = i;
    }

    void setSchool(string s)
    {
        school = s;
    }

    void setGrade(int g)
    {
        grade = g;
    }

    string getid() { return sid; }
    string getschool() { return school; }
    int getgrade() { return grade; }
};

class Worker : public Human
{
    string wid;

public:
    Worker() { cout << "Worker created...\n"; }
    ~Worker() { cout << "Worker destroyed...\n"; }

    void setWid(string w)
    {
        wid = w;
    }

    string getwid() { return wid; }
};

void print(Human &h)
{
    cout << h.getname() << ":" << h.getbirthdate() << endl;
}

void print(Student &s)
{
    cout << s.getname() << ":" << s.getbirthdate() << endl;
    cout << s.getid() << ":" << s.getschool() << ":" << s.getgrade() << endl;
}

void print(Worker &w)
{
    cout << w.getname() << ":" << w.getbirthdate() << endl;
    cout << w.getwid() << endl;
}

// int main()
// {
//     //stack memory, automatic deletion
//     cout << "------1--------\n";
//     Human h;
//     cout << "------2--------\n";
//     Student s;
//     cout << "------3--------\n";
//     Worker w;
//     cout << "------4--------\n";
//     return 0;
// }

// int main()
// {
//     //heap memory, need to delete manually;
//     cout << "------1--------\n";
//     Human *h;
//     h = new Human;
//     cout << "------2--------\n";
//     Student *s;
//     s = new Student;
//     cout << "------3--------\n";
//     Worker *w;
//     w = new Worker;
//     cout << "------4--------\n";

//     delete h;
//     delete s;
//     delete w;

//     return 0;
// }

int main()
{
    Human h;
    Student s;
    Worker w;
    h.setName("Amany");
    h.setBirthDate("10042004");
    print(h);
    s.setSid("123");
    s.setName("Ahmad");
    s.setBirthDate("20012010");
    s.setGrade(10);
    s.setSchool("IMAS");
    print(s);
    w.setWid("434");
    w.setName("Andy");
    w.setBirthDate("02101980");
    print(w);
    return 0;
}