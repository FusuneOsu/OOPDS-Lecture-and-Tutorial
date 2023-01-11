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
};

Point::Point() : x(0), y(0) {}
Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}
void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }
int Point::getX() const { return x; }
int Point::getY() const { return y; }

class Triangle
{
private:
    Point *corners;

public:
    Triangle();
    Triangle(const Point p[]);
    Triangle(const Triangle &);
    void setPoints(const Point p[]);
    void draw();
    void construct();
    Triangle &operator=(const Triangle &);
    ~Triangle();
};

Triangle::Triangle()
{
    corners = new Point[3];
}
Triangle::Triangle(const Point a[])
{
    corners = new Point[3];
    for (int i = 0; i < 3; i++)
    {
        corners[i].setX(a[i].getX());
        corners[i].setY(a[i].getY());
    }
}
Triangle::Triangle(const Triangle &t)
{
    corners = new Point[3];
    for (int i = 0; i < 3; i++)
    {
        corners[i].setX(t.corners[i].getX());
        corners[i].setY(t.corners[i].getY());
    }
}
Triangle &Triangle::operator=(const Triangle &t) //Overloading the = operator
{
    for (int i = 0; i < 3; i++)
    {
        corners[i].setX(t.corners[i].getX());
        corners[i].setY(t.corners[i].getY());
    }
    return *this;
}

Triangle::~Triangle()
{
    delete[] corners;
}
void Triangle::setPoints(const Point p[])
{
    for (int i = 0; i < 3; i++)
    {
        corners[i].setX(p[i].getX());
        corners[i].setY(p[i].getY());
    }
}
void Triangle::draw()
{
    cout << "Triangle:";
    for (int i = 0; i < 3; i++)
    {
        cout << "("
             << corners[i].getX()
             << ","
             << corners[i].getY()
             << ")";
    }
    cout << endl;
}

void Triangle::construct()
{
    corners = new Point[3];
}

int main()
{
    Point a[] = {Point(5, 7), Point(1, 2), Point(3, 4)};
    Triangle t;
    t.setPoints(a);
    t.draw();
    Triangle t2, t3;
    t3 = t2 = t;
    t.draw();
    t2.draw();
    t3.draw();
    t3.operator=(t2.operator=(t)); // t3=t2=t;
    return 0;
}

// int main()
// {
//     Point p(5, 6);
//     Point q;
//     q = p;
//     Point *ptr;
//     ptr = &p;
// }