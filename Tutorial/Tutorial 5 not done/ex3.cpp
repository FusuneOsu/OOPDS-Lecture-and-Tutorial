#include <iostream>
using namespace std;
class USBDisk
{
    int data;
    int size;

public:

    USBDisk(int sz = 0) { size = sz; } // both default and parameterized constructor

    USBDisk(const USBDisk &other) //can work as long as there are no pointers
    {
        size = other.size;

        //arr = new int[size];

        data = other.data;

        // (int i=0;-i<size; i++)
        //{arr[i] = other.arr[i];}
    }

    void setData(int d) { data = d; }
    void show()
    {
        cout << size << endl;
        cout << data << endl;
    }
};

int main()
{
    // 1
    USBDisk u0;
    u0.setData(9);
    u0.show();

    // 2
    USBDisk u1(5);
    u1.setData(10);

    // 3
    USBDisk u2(u1);
    u2.setData(20);

    // 4
    USBDisk u3 = u1;
    u3.setData(30);
    u1.show();
    u2.show();
    u3.show();

    // 1) Identify which constructor is called when executing the program for
    // the statements following the commented numbers 1,2,3, and 4.


    // 2) Explain what is shallow copy and how it is performed in this program.


    // 3) Change the declaration of data from int to int*. Modify the
    // constructor to allocate memory for the data pointer (allocate just one
    // int location). Modify the setData and show methods to deal with
    // pointer data rather than int data.


    // 4) Run the program and observe the output. Explain why u1, u2, and u3
    // show different size values but the same value for data when printed
    // out?


    // 5) Write a proper copy constructor to solve the issue in 4. Run the
    // program and check the output.


    // 6) At the end of the program, all objects u0, u1, u2, and u3 will be
    // destroyed. But the allocated memory for data never been released. This
    // is a memory leak. Define a destructor to overcome this issue.


    // 7) Add a cout statement to the copy constructor displaying “A copy is
    // created”. Then add the following C++ statements (USBDisk u4{u1};
    // USBDisk u5 = {u1};). Run the program and observe the output and
    // identify the constructors invoked.


    return 0;
}