#include <iostream>
#include "Student.hpp"
using namespace std;

class Student
{
 
    int id;
    string name;
    string faculty;

public:
    // 2) Add proper mutators inline to the class (to mutate all data members
    // individually).
    
    // 3) Add proper accessors inline to the class (to access all data members
    // individually).
    void setID(int ID);

    int getID();

    void setName(string n);

    string getName();

    void setFaculty(string f);

    string getFaculty();

};
    // 6) Change step 2 and step 3 to have the accessors and mutators written
    // outside the class. The class should contain only prototypes of these
    // methods.
    void setID(int ID)
    {this->id = ID;};

    int getID()
    {return id;}

    void setName(string n)
    {this->name=n;}

    string getName()
    {return name;}

    void setFaculty(string f)
    {this->faculty=f;}

    string getFaculty()
    {return faculty;}

int main()
{
    Student st; 
    // 4) Use the mutators in your program to replace the three lines commented
    // as 1,2,3.
    st.setID(10);
    st.setName("Alpha");
    st.setFaculty("FCI");
    
    // st.id = 10;         // 1 //st -> s
    // st.name = "Alpha";  // 2
    // st.faculty = "FCI"; // 3 //corrected the spelling of faculty
    // add your code below this line

    // 1) Explain what’s wrong with the program.
    //different name being initialized and used
    
    // 5) Use the accessors to print out the data members of s separated by “:”
    // on one line.
    cout << st.getID() << " : " << st.getName() << " : " << st.getFaculty() << " : " << endl;
    
    // 7) Define a function outside the class named print that will receive a
    // reference to an object of type Student and print out the data members
    // of that object. Invoke the method from main passing the object s to it.

    return 0;
}