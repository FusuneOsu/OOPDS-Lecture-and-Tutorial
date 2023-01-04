#include <iostream>
using namespace std;
class Square
{
private:
    int side;

public:
    Square(int s = 1)
    {
        cout << "Const ..."
             << endl;
        side = s;
    }
    ~Square() //destructor

    // 1.Only 1 destructor is allowed per class (i.e., it
    // cannot be overloaded)
    // 2.It is executed automatically when the object goes
    // out of scope

    {
        cout << "Destr ..."
             << endl;
    }
    void setSide(int v)
    {
        side = v;
    }
    int getSide()
    {
        return side;
    }
};

int main()
{
    Square sq(6);
    cout << sq.getSide()
         << endl;
    return 0;
}