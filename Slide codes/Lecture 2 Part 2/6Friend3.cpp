// A class is a friend of another Class
#include <iostream>
using namespace std;
class Printer;
class myPair
{
private:
    int x;
    int y;

public:
    friend class Printer;
    // Printer class is a friend of myPair class,
    // therefore, all member functions of Printer have
    // unrestricted access to all members of myPair
    // class, including the private members.
    myPair(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
};
class Printer
{
public:
    void show(myPair &p)
    {
        cout << p.x << ",";
        cout << p.y << endl;
    }
};

int main()
{
    myPair p{1, 3};
    Printer pr;
    pr.show(p);
    return 0;
}