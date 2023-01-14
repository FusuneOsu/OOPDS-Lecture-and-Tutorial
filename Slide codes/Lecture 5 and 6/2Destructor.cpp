#include <iostream>
using namespace std;

class Shape
{
private:
    int x;
    int y;
    string label;

public:
    Shape();
    Shape(int, int);
    Shape(int, int, string);
    void print();
    void setX(int);
    void setY(int);
    int getX();
    int getY();
    ~Shape();
};

class Circle : public Shape
{
private:
    double radius;
    string label;

public:
    Circle();
    Circle(int, int);
    Circle(int, int, double, const string &);
    void print();
    void setCenter(int, int);
    void setRadius(double r);
    double getRadius();
    ~Circle();
};

Shape::Shape()
{
    x = y = 0;
    label = "Shape";
    cout << label << " is created ()\n";
}
Shape::Shape(int x, int y)
{
    this->x = x;
    this->y = y;
    label = "Shape";
    cout << label
         << " is created (int,int)\n";
}
Shape::Shape(int x, int y, string label)
{
    cout << label
         << " is created (int,int,string)\n";
    this->x = x;
    this->y = y;
    this->label = label;
}
void Shape::print()
{
    cout << label << ".print ->";
    cout << "(" << x << "," << y << ")\n";
}
Shape::~Shape()
{
    cout << label << " is destroyed \n";
}

Circle::Circle()
{
    radius = 1.0;
    label = "C";
    cout << "Circle: " << label
         << " is created()\n";
}
Circle::Circle(int x, int y, double r, const string &lbl)
{
    radius = r;
    label = lbl;
    cout << "Circle: " << label
         << " is created(int,int,double,string)\n";
}
void Circle::print()
{
    cout << label << ".print -> at ";
    cout << "(" << getX() << "," << getY() << ")";
    cout << " with radius = " << radius
         << endl;
}
Circle::~Circle()
{
    cout << "Circle: " << label
         << " is destroyed"
         << endl;
}

int main()
{
    Shape s;
    s.print();
    Circle c;
    c.print();
    return 0;
}