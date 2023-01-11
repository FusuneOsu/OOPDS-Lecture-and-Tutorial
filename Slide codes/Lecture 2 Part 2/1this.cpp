// this->Implicit parameter passed to
// every member function
// it points to the object calling the
// function

#include <iostream>
using namespace std;

class Student
{
private:
    int sid;
    string name;
    float marks[5];
    float gpa;

public:
    Student()
    {
        sid = 0;
        name = "Default";
        for (int i = 0; i < 5; i++)
            marks[i] = 0;
        gpa = 0;
    }

    Student(int sid, string nm, float marks[], float gpa)
    {
        this->sid = sid;
        name = nm;
        for (int i = 0; i < 5; i++)
            this->marks[i] = marks[i];
        this->gpa = gpa;
    }
    void show()
    {
        cout << "ID :" << this->sid << endl
             << "Name :" << name << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++)
            cout << marks[i] << ":";
        cout << endl;
        cout << "GPA :" << gpa << endl;
    }
};

int main()
{
    float m[]{90.0f, 80.0f, 70.0f, 90.0f, 86.0f};
    string name = "Goh";
    Student st(10, name, m, 3.6f);
    st.show();
    return 0;
}