#include <iostream>

using namespace std;

class Point{
    int *x;
    int *y;

public:
    Point(){
        cout << "Constructed \n";
        x = new int (0);
        y = new int (0);
    }

    Point (const Point& oth){
        cout << "user copy contructor\n";
        x = new int(0);
        y = new int(0);
        *x = *(oth.x);
        *y = *(oth.y);
    }

    ~Point(){
        cout << "Deleted\n";
        delete x;
        delete y;
    }
    void setPoint(int p1, int p2){
        *x = p1;
        *y = p2;
    }
};

int main(){

    Point pt;
    pt.setPoint(10,15);

    {   
        Point pt2(pt);  // copy constructor
    }



    // for (int i=0; i<3;i++)
    // {
    //     Point x;
    // }
}