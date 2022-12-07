#include <iostream>
using namespace std;

class Point{
public:
    int x;
    int y;
};


class Circle{
    Point c;
    double rad;

public:
    void setCircle(double r, Point p){
        rad = r;
        c.x = p.x;
        c.y = p.y;
    }

    void setRad(double r){
        rad = r;
    }

    // area should never be declared as a data member
    // declare it as a function that returns the value
    double getArea(){
        return 3.1415 * rad * rad;
    }
};

int main(){
    Circle c;
    Point p{4,5};

    c.setCircle(5,p);
    c.setRad(100);

    cout << c.getArea() << endl;
}

// #include <iostream>
// using namespace std;

// class Point{
// public:
//     int x;
//     int y;
// };


// class Circle{
//     Point c;
//     double rad;
//     double area;

// public:
//     void setCircle(double r, Point p){
//         rad = r;
//         c.x = p.x;
//         c.y = p.y;
//         area = 3.1415 * r * r;
//     }

//     void setRad(double r){
//         rad = r;
//     }

//     double getArea(){
//         return area;
//     }
// };

// int main(){
//     Circle c;
//     Point p{4,5};

//     c.setCircle(5,p);
//     c.setRad(100);

//     cout << c.getArea() << endl;
// }