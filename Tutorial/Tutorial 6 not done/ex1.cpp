#include <iostream>
using namespace std;
class Coordinates
{
    int x;
    int y;

public:
    Coordinates() : x(0), y(0) {}
    Coordinates(int x, int y) : x(x), y(y) {}
    Coordinates(const Coordinates &ot)
    {
        x = ot.x;
        y = ot.y;
    }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int getX() const { return x; }
    int getY() const { return y; }
};
void print(const Coordinates &c)
{
    cout << c.getX() << "," << c.getY() << endl;
}
int main()
{
    // 1) In the main function create 2 objects c1 with the values (3,4) and c2
    // with the values (5,6). Then create 2 other objects c3 and c4 without
    // any initial values.
    Coordinates c1,c2,c3,c4;

    c1.setX(3);
    c1.setY(4);

    c2.setX(5);
    c2.setY(6);

    // 2) Print out the contents of (c1, c2, c3,and c4) using the print
    // function.

    print(c1);
    print(c2);
    print(c3);
    print(c4);

    // 3) For all of the following you must implement the functions and write a
    // test statements in the main function to test your implementation.

    // a) Overload the + operator so that it adds a given integer value to
    // both x and y of the object. The function must be a member of the
    // Coordinates class.

    // b) Overload the + operator to add two Coordinates by adding the xs and
    // ys together. The function must be a member of the Coordinates
    // class.

    // c) Overload the prefix ++ operator for the Coordinates class. The
    // function must be a member of the Coordinates class.

    // d) Overload the postfix ++ operator for the Coordinates class. The
    // function must be defined outside the Coordinates class.

    // e) Overload the the operator [] so that if passed and int value equal
    // to 0 returns x and 1 returns y, otherwise returns -1. The function
    // must be defined outside the Coordinates class.

    // f) Overload the == operator to return true if both objects are
    // identical and false otherwise. This method must be a member of the
    // class Coordinates.

    // g) Overload the >> operator to read two integers from keyboard and
    // insert these integers to x and y of an object. You will realize
    // that this method must be defined outside of the class and cannot be
    // a member of the class Coordinates.

    // h) Overload the << operator so that it display the data components of
    // the object to the screen followed by a newline (endl).
    return 0;
}