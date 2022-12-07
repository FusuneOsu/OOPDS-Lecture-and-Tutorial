#include <iostream>
using namespace std;
class Student
{
private:
    int id;
    string name;
    string faculty;
};
int main()
{
    Student s1;
    Student s2(10, "Alex", "FCI");
    Student s3{10, "Mary", "FOE"};

    // 1) Compile the above program and explain what’s wrong.
    
    // 2) Write a default constructor that will initialize the private data
    // members id to 0, name to “X”, and faculty to “Y”. The constructor
    // should also display a message with the name and “is created\n”.
    
    // 3) Write a parametrized constructor to set the private data members to
    // three values passed as parameters (id, name, faculty). The constructor
    // must display a message saying that the object’s name is created.
    
    // 4) Can we write inside the constructor (name = name;) where name is the
    // parameter passed to the method and the left name is the class data
    // member? How to discriminate between those two names?
    
    // 5) Explain which lines from the initial program invoke the default and
    // parametrized constructors.
    
    // 6) Write a destructor to the class Student. The destructor must display a
    // message saying the object with name is destroyed.
    
    // 7) Run the program and discuss the order of creation and destruction of
    // objects s1, s2, and s3 at the end of the program. Explain why such
    // order is generated.
    
    // 8) Can we overload the destructor?

    return 0;
}