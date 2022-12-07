#include <iostream>
using namespace std;
class USBDisk
{
    int *data;
    int size;

public:
    USBDisk(int sz = 4)
    {
        size = sz;
        data = new int[size];
    }
    USBDisk(const USBDisk &ot)
    {
        size = ot.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = ot.data[i];
    }
    ~USBDisk() { delete[] data; }
    void setData(int index, int value)
    {
        if (index < size)
            data[index] = value;
        else
            cout << "out of bound...\n";
    }
    void show()
    {
        cout << "size = " << size << endl;
        for (int i = 0; i < size; i++)
            cout << data[i] << endl;
    }
};
int main()
{
    USBDisk u1(3);
    u1.setData(0, 11);
    u1.setData(1, 23);
    u1.setData(2, 33);
    u1.show();

    // 1) Compile and run the program.
    // 2) Declare a class named Computer with
    // a) No data members
    // b) A public method named readDisk the has no return type and receives
    // a constant reference to USBDisk. ReadDisk is a friend of class
    // USBDisk. The method must display the data array elements of the
    // USBDisk object. You are not allowed to add new methods to the class
    // USBDisk and must access the data member directly.
    // c) A public method named writeDisk the has no return type and receives
    // a reference to USBDisk, and int index, and an int value. writeDisk
    // is a friend of class USBDisk. The method must assign the int value

    // passed to data array element at index pos directly without the use
    // of any methods from USBDisk.

    // 3) In the main function,
    // a) declare an object t of type Computer.
    // b) Invoke the method readDisk of t passing u1 to it as a parameter.
    // c) Invoke the method writeDisk of t passing u1, 1, and 88 as
    // parameters.
    // d) Show the contents of u1.

    // 4) Define the class Computer as a friend of USBDisk and rerun the program.

    return 0;
}