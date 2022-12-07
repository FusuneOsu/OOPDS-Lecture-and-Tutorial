#include <iostream>
using namespace std;

class Coordinates
{
    int x;
    int y;

public:
    Coordinates() //default constructor
    {
        x = 0;
        y = 0;
        cout << "Default constr. (" << x << ", "
             << y << ")...\n";
    }
    Coordinates(int x, int y) //parameterized constructor
    {
        // 1) Complete the parameterized constructor to initialize x and y.
        this->x = x;
        this->y = y;
        cout << "Param. constr. (" << x << ", " << y << ")...\n";
    }

    // 2) Complete the accessors (setX and setY) so that they change the value
    // of x and y.
    void setX(int x)//accessor
    {this->x = x;}

    void setY(int y)
    {this->y = y;}

    ~Coordinates()//destructor
    {
        cout << "Destructor (" << x << ", " << y << ")...\n";
    }
    void show()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Coordinates p1, p2(-10, 10);
    p1.setX(9);
    p1.setY(8);
    p1.show();
    p2.show();

    // 3) compile and run the program and observe the order of execution of
    // constructors and the destructor.

    //output:
    // Default constr. (0, 0)...  
    // Param. constr. (-10, 10)...
    // (9, 8)
    // (-10, 10)
    // Destructor (-10, 10)...    
    // Destructor (9, 8)...

    // 4) Add a public static data member of type int to the class named
    // objCount. Increment this variable in the constructors and decrement it
    // in the destructor. Initialize the static data member objCount to 0.

    // 5) From the main program, print out the value of objCount at the
    // beginning and at the end of the program (before the return statement).

    return 0;
}