#include <iostream>
#include <cstring>
using namespace std;
struct Student
{
    int id;
    string name;
    string faculty;
}S1,S1_copy ;

int main()
{

    // (1) Declare a local variable named s1 of type Student initialized to the
    // values 100 for id, “Goh Chien Lee” to the filed name, and “FCI” to the
    // data field faculty.
    Student S1{100,"Goh Chien Le","FCI"};
    
    // (2) Write one cout statement to print the data elements of the object s1
    // each on a separate line.
    cout << S1.id << endl;
    cout << S1.name << endl;
    cout << S1.faculty << endl;
    
    // (3) Change the value of the field id of object s1 to 99.
    S1.id = 99;
    cout << S1.id << endl;

    // (4) Declare an object of type Student named s2.
    Student s2;

    // (5) Can we assign s1 to s2 directly without elementwise assignment?
    memcpy (&S1_copy, &s2, sizeof(s2));
    cout << endl;

    // (6) Repeat what you have done in step 2 for s2.
    cout << s2.id << endl;
    cout << s2.name << endl;
    cout << s2.faculty << endl;
    
    // (7) Create an array of 5 students named tcp1201 then fill this array with
    // some data of your choice (make sure at least 2 has the faculty field
    // set to “FCI”).
    Student tcp1201[5];

    tcp1201[0].id = 200;
    tcp1201[0].name = "Kevin";
    tcp1201[0].faculty = "FOE";

    tcp1201[1].id = 201;
    tcp1201[1].name = "Shahrul";
    tcp1201[1].faculty = "FCI";

    tcp1201[2].id = 202;
    tcp1201[2].name = "Jean";
    tcp1201[2].faculty = "FOM";

    tcp1201[3].id = 203;
    tcp1201[3].name = "Sebastian";
    tcp1201[3].faculty = "FCI";

    tcp1201[4].id = 204;
    tcp1201[4].name = "Keke";
    tcp1201[4].faculty = "FCM";
    
    // (8) Print out only those objects with field member faculty equal to “FCI”.
    
    
    // (9) Change the definition of the Student to become a class rather than
    // struct. Recompile the program and explain what is wrong.
    
    // (10) Is struct and class are the same?

return 0;
}