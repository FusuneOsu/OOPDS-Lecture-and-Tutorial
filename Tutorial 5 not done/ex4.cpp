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
    ~USBDisk()
    {
        delete[] data;
    }
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
float average(const USBDisk &c)
{
}
int main()
{
    USBDisk u1(3);
    u1.setData(0, 11);
    u1.setData(1, 23);
    u1.setData(2, 33);
    u1.show();
    cout << average(u1) << endl;

    // (1) Declare the function average as a friend of class USBDisk.
    // (2) Complete the function average so that it returns the average of the
    // array (data) elements.
    // (3) In the main function, write a statement to test your average function
    // and display the value.
    
    return 0;
}