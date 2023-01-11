#include <iostream>
using namespace std;

class myPair
{
private:
    int x;
    int y;

    // Can be used to access static member variables
    // Can be called before any class objects are created
    static int NoOfObjects;

public:
    myPair(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
        NoOfObjects++;
    }
    ~myPair() { NoOfObjects--; }
    static int Counter()
    {
        return NoOfObjects;
    }
    void setPair(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    myPair getPair() const
    {
        return myPair(x, y);
    }
    int getX() { return x; }
    int getY() { return y; }
};

int myPair::NoOfObjects = 0; //cannot use this->NoOfObjects
int main()
{
    myPair p1(3, 4);
    cout << p1.Counter() << endl;
    myPair p2;
    cout << myPair::Counter() << endl;
    myPair pa[3];
    cout << pa[2].Counter() << endl;
    return 0;
}