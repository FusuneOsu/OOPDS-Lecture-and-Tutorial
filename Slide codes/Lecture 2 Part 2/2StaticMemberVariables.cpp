#include <iostream>
using namespace std;

class myPair
{
private:
    int x;
    int y;

public:
    // One instance of the variable for the entire class
    // It is shared by all objects of the class
    static int NoOfObjects;

    myPair(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
        NoOfObjects++;
    }
    ~myPair()
    {
        NoOfObjects--;
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

void print(const myPair &p)
{
    cout << p.getPair().getX()
         << ","
         << p.getPair().getY()
         << endl;
}
int myPair::NoOfObjects = 0;
int main()
{
    myPair p1(3, 4);
    cout << p1.NoOfObjects << endl;
    myPair p2;
    cout << myPair::NoOfObjects << endl;
    myPair pa[3];
    cout << pa[2].NoOfObjects << endl;
    return 0;
}