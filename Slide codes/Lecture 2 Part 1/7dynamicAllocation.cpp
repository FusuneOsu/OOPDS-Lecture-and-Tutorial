#include <iostream>
using namespace std;
class myArray
{
private:
    int size;
    int *data;

public:
    myArray()
    {
        size = 4;
        data = new int[size];
    }
    void setItem(int index, int value)
    {
        data[index] = value;
    }
    int getItem(int index)
    {
        return data[index];
    }
};

int main()
{
    myArray a;
    a.setItem(0, 10);
    a.setItem(1, 20);
    cout << a.getItem(1)
         << endl;
    return 0;
}