#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;

public:
    Point();
    Point(int x, int y);
    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;
    void display();
    //Point operator+(const Point &p);
    //Point& operator+(int x);
    friend Point operator+ (const Point &p, const Point &q);
};

Point::Point() : x(0), y(0) {}
Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}
void Point::setX(int x)
{
    this->x = x;
}
void Point::setY(int y)
{
    this->y = y;
}
int Point::getX() const
{
    return x;
}
int Point::getY() const
{
    return y;
}
void Point::display()
{
    cout << "(" << x << "," << y << ")" << endl;
}

Point operator+ (const Point &p, const Point &q)
{
Point z;
z.x =p.x + q.x;
z.y =p.y + q.y;
return Point(z.x, z.y);
}

// Point& Point::operator+ (int a)
// {
// x = x + a;
// y = y + a;
// return *this;
// }

// this statement is equal to the bottom one
//  Point Point::operator+ (const Point &p)
//  {
//  return Point(x+p.x,y+p.y);
//  }
// Point Point::operator+(const Point &p)
// {
//     Point t;
//     t.x = x + p.x;
//     t.y = y + p.y;
//     return t;
// }

//Overloading the + operator as a member function
// int main()
// {
//     Point p1(10, 20);
//     Point p2(1, 1);
//     Point p3;
//     p3 = p1 + p2;
//     p1.display();
//     p2.display();
//     p3.display();
//     return 0;
// }

//Overloading the + operator as a member function
// int main( )
// {
// Point p1(10,20);
// Point p2(1,1);
// Point p3(3,5);
// p3 = p3 + 6;
// p1.display();
// p2.display();
// p3.display();
// return 0;
// }

//Overloading the + operator as a friend function
int main( )
{
Point p1(10,20);
Point p2(1,1);
Point p3;
p3 = p1 + p2;
p1.display();
p2.display();
p3.display();
return 0;
}

