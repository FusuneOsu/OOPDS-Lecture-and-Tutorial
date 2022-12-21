#ifndef SHAPE_H
#define SHAPE_H
#include <string>
using namespace std;
class Shape
{
private:
    string label;
    int x;
    int y;

public:
    Shape();
    Shape(string, int, int);
    Shape(const string &label);
    string getLabel();
    void setLabel(string);
    int getX();
    int getY();

    // (7) Add the virtual keyword in front of the draw member function of the Shape class and rerun
    // the main function in the previous step. Discuss and document your observations.   
    virtual void draw()=0;
    //virtual void draw();

    //(4) Add the keyword virtual in front of the destructor of the Shape class (can be done only in the
    //header file) and rerun the program in step 3 then discuss the difference.
    virtual ~Shape();
};
#endif