#include <iostream>
using namespace std;

struct PersonInfo
{
    string name,
        address,
        city;
};
struct Student
{
    int studentID;
    PersonInfo pData;
    short year;
    double gpa;
};

void show(Student &st)
{
    cout << st.studentID << endl

         << st.pData.name << endl
         << st.pData.address << endl
         << st.pData.city << endl

         << st.year << endl
         << st.gpa << endl;
}

// int main()
// {
//     Student s3{10, {"Ng Hu", "MMU", "cyberjaya"}, 2010, 3.4};
//     show(s3);
//     return 0;
// }

void printInfo(PersonInfo &p)
{
    cout << p.name << endl
         << p.address << endl
         << p.city << endl;
}

int main()
{
    Student s3{10,
               {"Ng Hu", "MMU", "cyberjaya"},
               2010,
               3.4};
    show(s3);
    printInfo(s3.pData);
    return 0;
}
