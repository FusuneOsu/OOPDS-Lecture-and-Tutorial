#include <iostream>
#include <fstream>

using namespace std;

class Student
{
public:
    int id;
    string name;
    string faculty;
};

void writeBinary(Student arr[], int sz)
{
    ofstream myFile("data.bin", ios::out | ios::binary);
    for (int i = 0; i < sz; i++)
        myFile.write((char *)&arr[i], sizeof(arr[i]));
    myFile.close();
}

void readBinary()
{
    ifstream myFile("data.bin", ios::in | ios::binary);
    Student s1;
    while (!myFile.eof())
    {
        myFile.read((char *)&s1, sizeof(s1));
        cout << s1.id << " : " << s1.name << " : " << s1.faculty << endl;
    }
    myFile.close();
}

int main()
{
    Student tcp1201[5];
    
    tcp1201[0].id = 1;
    tcp1201[0].name = "Alex";
    tcp1201[0].faculty = "FOE";

    tcp1201[1].id = 2;
    tcp1201[1].name = "Mary";
    tcp1201[1].faculty = "FCI";

    tcp1201[2].id = 3;
    tcp1201[2].name = "Choi";
    tcp1201[2].faculty = "FOE";
    
    tcp1201[3].id = 4;
    tcp1201[3].name = "Wong";
    tcp1201[3].faculty = "FCI";
    
    tcp1201[4].id = 5;
    tcp1201[4].name = "Pang";
    tcp1201[4].faculty = "FOE";
    
    writeBinary(tcp1201, 5);
    readBinary();

    // (1) Study the following program carefully. You are expected to understand
    // the binary files concept and its relationship to struct.
    
    // (2) Change the definition struct student to class student and alter the
    // rest of the program so that the program will compile and generate the
    // same output.
    //-> Change struct to class and make the class public
   
    // (3) Add code to the end of the program to read and print out the 3rd element
    // in the file directly and without reading the whole file.
    return 0;
}