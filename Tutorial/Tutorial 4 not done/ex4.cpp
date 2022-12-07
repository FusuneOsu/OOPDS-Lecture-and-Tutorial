#include <iostream>
#include <memory>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;
// Design and implement four classes Staff, Hospital, Department and Address.

// 1. Create a class named Staff with at least the following data members
// (id, name, birthdate, education, certification, address, and main
// language).

class Staff
{
    private:
        int id;
        string name;
        string birthdate;
        string education;
        string certification;
        Address Staffaddress;
        string MainLanguage;

    public:

};

// 2. Design a proper Address class that stores and manipulates the address
// elements.

class Address
{
    private:
        int street_number;
        int postcode;
        string town;
        string state;

    public:

    Address(int snum, int pcode, string ttown, string sstate)
    {
        street_number = snum;
        postcode = pcode;
        town = ttown;
        state = sstate;
    }

    void setStreet(int snum){street_number = snum;}
    void setPostcode(int pcode){postcode = pcode;}
    void setTown(string townname){town = townname;}
    void setState(string statename){state = statename;}

    int getStreet() const {return street_number;}   
    int getPostcode() const {return postcode;} 
    string getTown() const {return town;} 
    string getState() const {return state;} 
};

// 3. The Hospital class must have at least the following members (Name as a
// string, Address as an Address object, phone, fax, e-mail, an array of
// departments, and any fields you feel necessary)

class Hospital
{
    private:
    string Name;
    Address HospAddress;
    int phone;
    int fax;
    string email;
    Department departments[2];

    public:

    Hospital(string n, Address ha, int p, int f, string e, Department d[])
    {
        Name = n;
        HospAddress = ha;
        phone = p;
        fax = f;
        email = e;
        departments = d;
    }
};

// 4. The Department class has at least the following members (name, an
// array of Staff, number of staff, and any number of data fields you
// find necessary).

class Department
{
    private:
    string name;
    vector<Staff> arrStaff;
    int numOfStaff;

    public:

};

int main()
{
// 5. In the main function:
    // a. Create 7 Address objects and initialize them with some data.
    Address Add1 (34,48904,"Batherson","Perak");
    Address Add2 (22,23048,"Silverstone","Kelantan");
    Address Add3 (77,32921,"Dunlop","Johor");
    Address Add4 (9,23890,"Fuji","Pahang");
    Address Add5 (1,29032,"Kirrmayer","Kedah");
    Address Add6 (15,78293,"Prost","Melaka");
    Address Add7 (233,17862,"Rhubarb","Negeri Sembilan");

    // b. Create 6 objects of Staff and initialize them with data of your
    // choice. Add an address object to each staff object created.

    Staff staff1 ();
    Staff staff2 ();
    Staff staff3 ();
    Staff staff4 ();
    Staff staff5 ();
    Staff staff6 ();

    // c. Create 2 department objects. Add the first 3 Staff objects to
    // the first department object and the last three to the second
    // department.

    Department dep1 ();
    Department dep2 ();

    // d. Create an object of type Hospital. Initialize the address of the
    // hospital to the 7th address. Add the two departments to the
    // hospital.

    Hospital hospitale ();
    
    // e. Display all the components you created with proper functions and
    // messages.
}