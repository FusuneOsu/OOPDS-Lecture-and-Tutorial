#include <iostream>
using namespace std;
class Coordinates
{
    int x;
    int y;
    static int objCount;

public:
    Coordinates()
        : x(0), y(0)
    {
        objCount++;
    }
    Coordinates(int x, int y)
        : x(x), y(y)
    {
        objCount++;
    }
    ~Coordinates()
    {
        objCount--;
    }
    // (1) add a method to return the value of objCount
    int getObjCount()
    {
        return objCount;
    }

    void show()
    {
        cout << "(" << x
             << ", " << y << ")"
             << endl;
    }
};
// (2) initialize the static data member here
int Coordinates::objCount = 0;

int main()
{
    // (3) display the number of objects created so far
    cout << Coordinates::getObjCount() << endl;
    Coordinates p1;

    // (4) display the number of objects created so far
    {
        Coordinates p2(1, 2);
        // (5) display the number of objects created so far
    }
    Coordinates p3[3];
    
    // (6) display the number of objects created so far
    return 0;
}