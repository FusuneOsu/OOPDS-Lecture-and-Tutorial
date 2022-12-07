#include <iostream>
using namespace std;
class Data
{
    int *data;
    int size;

public:
    Data(int sz = 5) : size(sz)
    {
        cout << "Constructor...\n";
        data = new int[size];
    }
    ~Data()
    {
        cout << "Destructor...\n";
        if (data != nullptr)
            delete[] data;
    }
    Data(const Data &ot)
    {
        cout << "Copy constructor...\n";
        size = ot.size;
        if (ot.data != nullptr)
        {
            data = new int[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = ot.data[i];
            }
        }
        else
            data = nullptr;
    }
    Data &operator=(const Data &ot)
    {
        cout << "Copy assignment...\n";
        if (&ot != this)
        {
            size = ot.size;
            data = new int[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = ot.data[i];
            }
        }
        return *this;
    }
    Data(Data &&ot)
    {
        cout << "Move constructor...\n";
        size = ot.size;
        data = ot.data;
        ot.data = nullptr;
    }
    Data &operator=(Data &&ot)
    {
        cout << "Move assignment ...\n";
        size = ot.size;
        data = ot.data;
        ot.data = nullptr;
        return *this;
    }
    int getSize() const
    {
        return size;
    }
    int getData(int i) const
    {
        if (i >= 0 && i < size)
        {
            return data[i];
        }
        else
        {
            cout << "out of bound...\n";
            return -1;
        }
    }
    void setData(int i, int value)
    {
        if (i >= 0 && i < size)
        {
            data[i] = value;
        }
        else
        {
            cout << "out of bound...\n";
        }
    }
};
void print(const Data &d)
{
    cout << "Size =" << d.getSize() << endl;
    for (int i = 0; i < d.getSize(); i++)
    {
        cout << d.getData(i) << " : ";
    }
    cout << endl;
}
void fillObject(Data &d)
{
    for (int i = 0; i < d.getSize(); i++)
    {
        d.setData(i, rand() % 20);
    }
}
int main()
{
    srand(time(NULL));

    // 1) Identify and discuss the constructors (default, parametrized, copy, and move), destructor, copy
    // assignment, and the move assignment methods.
    // 2) Perform the following tasks:
    // a. Declare a Data object named d with data size equal to 5.
    // b. Call the fill function to fill it with random numbers.
    // c. Display the values stored in data of the object d.
    // 3) Perform the following tasks:
    // a. Using a copy constructor, declare an Data object named b assigned to the object d.
    // b. Change the 2nd element in the data array of b to 99.
    // c. Display both objects b and d.
    // 4) Perform the following tasks:
    // a. Declare a Data object named f by moving the contents of object b to it.
    // b. Display the contents of data in f.
    // c. Can you print the values of data in b?
    // 5) Perform the following tasks:
    // a. Declare a Data object named s using using a prvalue [Data(6)].
    // b. Display the values in s.
    // 6) By assigning f to d, which operator overloading is invoked?
    // 7) If you write the statement [d = Data(6);] what happens?

    return 0;
}