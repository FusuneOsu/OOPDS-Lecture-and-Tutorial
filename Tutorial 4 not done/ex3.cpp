#include <iostream>
#include <memory>
using namespace std;
class Shape
{
    int x;
    int y;
    static int numObjects;

public:
    Shape();
    Shape(int x, int y); //x and y are formal arguements or parameters
    ~Shape();
    static int getNumObj();
};

Shape::Shape() { numObjects++; }

Shape::Shape(int x, int y) : x(x), y(y)
{
    numObjects++;
}
Shape::~Shape() { numObjects--; }

int Shape::getNumObj()
{
    return numObjects;
}
int Shape::numObjects = 0;

int main()
{
    Shape s1;
    cout << Shape::getNumObj() << endl;
    {
        Shape s[5];
        cout << Shape::getNumObj() << endl;
    }
    cout << Shape::getNumObj() << endl;

    

    // 1) Study the above program and discuss the static keyword used.
    // no static = instance variable 
    // with static = class variable

    // 2) Explain why we need the static keyword and the line (int
    // Shape::numObjects = 0;).
    // -> to initialize numObjects to 0 instead of other numbers

    // 3) Can we use the object name when accessing the method (getNumObj())
    // rather than the class name.
    // ->No 

    // 4) If we remove the static word from the declaration of the method
    // (getNumObj()), can we invoke the method using the class name?
    // ->No

    // 5) Define a unique_ptr to a Shape object. Display numObjects created. Does
    // it increment numObjects? Create an object and assign it to uptr using
    // make_unique. Does this increment numObjects?
    Shape s2;
    unique_ptr<Shape> uptr;
    //uptr = make_unique<s2>;
    cout << Shape::getNumObj << endl;

    return 0;
}