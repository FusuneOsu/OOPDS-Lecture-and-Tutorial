#include <iostream>
using namespace std;

class Shape
{
private:
    int x;
    int y;

public:
    Shape()
    {
        cout << "def Shape ..." << endl;
        x = y = 0;
    }
    Shape(int x, int y)
    {
        cout << "param Shape ..." << endl;
        this->x = x;
        this->y = y;
    }
    void print()
    {
        cout << "print Shape fun..." << endl;
        cout << "(" << x << ","
             << y << ")" << endl;
    }
    int getX() { return x; }
    int getY() { return y; }
    void setX(int v) { x = v; }
    void setY(int v) { y = v; }
};

class Rectangle : public Shape
{
private:
    int width;
    int height;

public:
    Rectangle()
    {
        cout << "def. Rectangle ..." << endl;
        this->setX(0);
        this->setY(0);
        width = height = 0;
    }
    Rectangle(int x, int y, int w, int h)
    {
        cout << "Param. Rectangle ..." << endl;
        this->setX(x);
        this->setY(y);
        width = w;
        height = h;
    }
    void print()
    {
        cout << "Rectangle print fun ..." << endl;
        cout << "Rectangle at" << endl;
        cout << getX() << "," << getY() << endl;
        cout << width << "," << height << endl;
    }
};

int main()
{
    cout << " ----1----" << endl;
    Shape s(0, 1);
    cout << " ----2----" << endl;
    Rectangle r(1, 2, 5, 6);
    cout << " ----3----" << endl;
    s.print();
    cout << " ----4----" << endl;
    r.print();
    cout << " ----5----" << endl;
    return 0;
}