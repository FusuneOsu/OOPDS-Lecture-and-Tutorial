#include <iostream>
using namespace std;

void print(int *p, int size)
{
    for (int i = 0; i < size; i++)
        cout << p[i] << ":";
    cout << endl;
}

void print1(int *p, int size)
{
    for (int i = 0; i < size; i++)
        cout << *(p + i) << ":";
    cout << endl;
}

int main(int argc, const char *argv[])
{
    int a[] = {1, 2, 3, 4, 5};
    print(a, 5);
    print1(a, 5);
    return 0;
}