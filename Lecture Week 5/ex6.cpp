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
        cout << "Default .......\n";

    }

    Point(int a, int b){
        alloc();
        *x = a;
        *y = b;
        cout << "Param .......\n";
    }

    ~Point(){
        dealloc();
        cout << "destructor\n";
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
        cout << "Copy ......\n";
    }

    // & is to allow the form a=b=c; not just a = b;

    Point& operator=(const Point &rightside){
        cout << "=   operator .....\n";
        *x = *(rightside.x);
        *y = *(rightside.y);
        return *this;
    }

    // Point operator+(const Point &rightside){
    //     cout << "+   operator .....\n";
    //     Point temp;
    //     *(temp.x) = *x + *(rightside.x);
    //     *(temp.y) = *y + *(rightside.y);
    //     return temp;
    // }

    Point operator+(const Point &rightside){
        cout << "+   operator .....\n";
        int xx = *x + *(rightside.x);
        int yy = *y + *(rightside.y);
        return Point(xx,yy);
    }

    Point operator*(const Point &rightside){
        cout << "*   operator .....\n";
        Point temp;
        *(temp.x) = *x * *(rightside.x);
        *(temp.y) = *y * *(rightside.y);
        return temp;
    }

    bool operator==(const Point &rightside){
        cout << "==   operator .....\n";
        bool b1 =  *x == *(rightside.x);
        bool b2 =  *y == *(rightside.y);
        return b1 && b2;
    }

    int operator[](int index){
        if (index == 0)
            return *x;
        else if (index == 1)
            return *y;
        else
            return -1;
    }

    friend ostream& operator<<(ostream &out, const Point& p);
    friend istream& operator>>(istream &in, Point& p);
};

ostream& operator<<(ostream &out, const Point& p) {
    cout << "<< Operator ....\n";
    out << "(" << *(p.x) << "," << *(p.y) << ")";
    return out;
} 

istream& operator>>(istream &in, Point& p){
    cout << "Enter x and y coord: ";
    in >> *(p.x) >> *(p.y);    
    return in;
}

void print(const Point &r){
    r.getPoint();
}


// the following functions for new and delete
// overoads the system's new and delete functions.
// 
void* operator new(size_t size){
    cout << "Sharaf new operator ........\n";
    return malloc(size);
}

void operator delete(void *ptr){
    cout << "Sharaf delete operator ........\n";
    free(ptr);
}

int main(){
    Point p(1,5);

    Point y = p;   // calls copy constructor

    Point q;
    q = p;         // does this call the copy constructor?
    
    print (q);

    Point t;
    t = p + q + p;

    print (t);

    y.setPoint(8,7);

    print (p);
    print (y);

    p = p.operator+(y);  // same as p = p + y;
    
    if (p == y)
        cout << "Equal" << endl;
    else
        cout << "Not equal\n";

    p = p * y;
    print(p);

    Point ppt(p);
    cout << ppt << endl;

    cin >> p;
    cout << p << endl;

    cout << p[0] << ":"        // p[0]  --> returns *x
         << p[1] << ":"        // p[1]  --> returns *y
         << p[3] << endl;      // p[>1] --> -1
}