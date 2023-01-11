#include <iostream>
using namespace std;

class Square
{
private:
    int side;

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
    }
    int getSide() const //must have const keyword to call Square member functions because externel function is using const
    {
        // size = 20; // causes error
        return side;
    }
};

void showData(const Square &s)
{
    cout << s.getSide() << endl;
    //s.setSide(20); // causes error
}

int main()
{
    Square sq(10);
    showData(sq);
    cout << sq.getSide()
         << endl;
    return 0;
}