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
    ~myArray()
    {
        delete data; cout<<"hah gayyyyy"<<endl; //delete in the heap
    }
    void setItem(int index, int value)
    {
        data[index] = value; //store in the heap
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
    a.setItem(5,100);
    cout << a.getItem(1)
         << endl;
    cout << a.getItem(5)
         << endl;
    return 0;
}