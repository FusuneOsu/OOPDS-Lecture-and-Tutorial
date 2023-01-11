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
    void setSide(int v) { side = v; }
    int getSide() { return side; }
};

// pass to this function by value
// the created square s will get destroyed by the destructor
//  void print(Square s)
//  {
//      cout << s.getSide()
//           << endl;
//      s.setSide(20);
//      cout << s.getSide()
//           << endl;
//  }

// pass to this function by reference
// s will store a referece to sq in the main
void print(Square &s)
{
    cout << s.getSide()
         << endl;
    s.setSide(20);
}

// pass by pointer
// will POINT to sq in the main
// sq in the main needs to be &sq because *ps can only store addresses
//     void print(Square *ps)
// {
//     cout << ps->getSide()
//          << endl;
//     ps->setSide(20);
// }

int main()
{
    Square sq(10);
    print(sq);
    //print(&sq);
    cout << sq.getSide() << endl;
    return 0;
}