//A Function member of a class as a Friend of another Class

#include <iostream>
using namespace std;

class myPair; // forward declaration
class Printer
{
public:
    void show(myPair &p);
};
class myPair
{
private:
    int x;
    int y;

public:
    myPair(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    void setPair(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    friend void Printer::show(myPair &p);
};

void Printer::show(myPair &p)
{
    cout << p.x << ",";
    cout << p.y << endl;
}
int main()
{
    myPair p{1, 3};
    Printer pr;
    pr.show(p);
    return 0;
}