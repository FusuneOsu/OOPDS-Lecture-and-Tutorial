#include <iostream>
using namespace std;

class Point {
int x;
int y;
public:
Point();
Point (int x, int y);
void setX(int x);
void setY(int y);
int getX()const;
int getY()const;
};

Point::Point():x(0),y(0){ }
Point::Point(int x, int y){
this->x = x;
this->y = y;
}
void Point::setX(int x){ this->x = x; }
void Point::setY(int y){ this->y = y; }
int Point::getX()const{ return x; }
int Point::getY()const{ return y; }

int main() {
Point p(5,6);
Point q;
q = p;
Point *ptr;
ptr = &p;
}