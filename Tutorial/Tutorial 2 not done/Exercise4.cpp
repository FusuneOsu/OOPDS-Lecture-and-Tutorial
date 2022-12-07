#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
    string fName;
    string lName;
    char gender;
    int bDay;
    int bMonth;
    int bYear;
};

int main()
{
    ifstream infile;
    Student oopds[5];
    // insert your code below this line

    // (1) Write a C++ statement to open the file “oopds.csv” and associate it with the infile handler.
    
    // (2) Check if the file exists in the path, otherwise display a message saying “File not found” and abort
    // the program.
    
    // (3) Read the data from the file handled by infile and store them into the oopds array of Student struct
    // defined earlier. Make sure you read the data until the end of the file.
    
    // (4) Write a for loop to loop through the oopds array and print the data on the screen.
    
    // (5) Close the file.
    return 0;
}