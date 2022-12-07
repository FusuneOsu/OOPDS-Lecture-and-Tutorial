#include <iostream>
using namespace std;

class Point {
    int *x;
    int *y;

    void alloc(){
        x = new int;
        y = new int;
    }

    void dealloc(){
        delete x;
        delete y;
    }
public:
    Point(){
        alloc();
        *x = 0;
        *y = 0;
    }

    Point(int a, int b){
        alloc();
        *x = a;
        *y = b;
    }

    ~Point(){
        dealloc();
    }

    void setPoint(int f, int g){
        *x = f;
        *y = g;
    }

    void getPoint() const {
        cout << "(" << *x 
             << ", " 
             << *y << ")\n";
    }

    // replacing the default copy constructor
    // to perform deep copy rather than shallow
    // copy
    Point(const Point& other){
        alloc();
        *x = *(other.x);
        *y = *(other.y);
    }
};

void print(const Point &r){
    r.getPoint();
}

int main(){
    Point p1(10,5);
    print(p1);
    
    
    Point a[3];
    for (int i=0; i<3; i++)
        print(a[i]);
    
    // create a new object p2 and copy the content 
    // of object p1 to it
    Point p2(p1);    // same as Point p2 = p1; 

    // calls copy constructor
    // it is a constructor that initializes an object using 
    // othe objects
    // system creates a default constructor, copy constructor


    p1.setPoint(8,8);

    print (p1);
    print (p2);
    

    Point y = p1;
    print (y);

}