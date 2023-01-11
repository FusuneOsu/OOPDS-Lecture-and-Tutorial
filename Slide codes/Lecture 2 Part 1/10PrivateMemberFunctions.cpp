#include <iostream>
using namespace std;
class Square
{
private:
    int side;
    void incr()
    {
        side++;
    }

public:
    Square(int s = 1)
    {
        cout << "Const ..." << endl;
            side = s;
    }
    ~Square()
    {
        cout << "Destr ..." << endl;
    }
    void setSide(int v)
    {
        side = v;
        incr(); // ok
    }
    int getSide()
    {
        return side;
    }
};

int main()
{
    Square sq(1);
    sq.setSide(5);
    //sq.incr(); // will cause compile error
    cout << sq.getSide()
         << endl;
    return 0;
}