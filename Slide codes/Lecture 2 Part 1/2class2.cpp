#include <iostream>
using namespace std;

class circle
{
private:
    double radius;

public:
    void store(double);
    double area(void);
    void display(void);
};

// member function definitions
void circle::store(double r)
{
    radius = r;
}
double circle::area(void)
{
    return 3.14 * radius * radius;
}
void circle::display(void)
{
    cout << "r = " << radius << endl;
}

int main()
{
    circle c;
    c.store(5.0);
    cout << "The area of circle c is "
         << c.area()
         << endl;
    c.display();
}