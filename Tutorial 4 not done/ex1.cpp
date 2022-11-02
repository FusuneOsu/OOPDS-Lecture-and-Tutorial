#include <iostream>
#include <memory>
using namespace std;
class Timer
{
private:
    int hour;
    int minute;
    int second;
};
Timer subtract(const Timer &y, const Timer &x)
{
    bool error = false;
    Timer z;
    int hy = y.getHour();
    int hx = x.getHour();
    int my = y.getMinute();
    int mx = x.getMinute();
    int sy = y.getSecond();
    int sx = x.getSecond();
    int hz = hy - hx;
    int mz = my - mx;
    int sz = sy - sx;
    if (hz < 0)
        return Timer(-1, -1, -1);
    else
    {
        if (my < mx)
        {
            hz--;
            mz += 60;
        }
        if (sy < sx)
        {
            mz--;
            sz += 60;
        }
    }
    z.setHour(hz);
    z.setMinute(mz);
    z.setSecond(sz);
    return z;
}

int main()
{
    Timer x(10, 34, 19);
    Timer y;
    y.setHour(13);
    y.setMinute(20);
    y.setSecond(12);
    Timer w = subtract(y, x);
    x.display();
    y.display();
    w.display();
    unique_ptr<Timer> uptr1;
    uptr1 = make_unique<Timer>(9, 35, 10);
    unique_ptr<Timer> uptr2;
    uptr2 = make_unique<Timer>(12, 01, 6);
    uptr1->display();
    uptr2->display();
    Timer tt = subtract(*uptr2, *uptr1);
    tt.display();

    // (1) Complete the definition of the class Timer by implementing a default
    // constructor, a parametrized constructor, a destructor, mutators for
    // each individual data member, an accessor for each individual data
    // member, and a display method to display the value of the timer object
    // data members separated by “:”.
    // (2) Declare a object x of type Timer with initial values (10,34,19).
    // (3) Declare an object y so that the default constructor is invoked.
    // (4) Set the data members of y using mutators to 13:20:12.
    // (5) Declare an object w and assign the returned value from calling the
    // function subtract passing y first then x.
    // (6) Display the object contents of x, y, and w.
    // (7) Declare a unique_ptr to a Timer object (name it uptr1) and initialize
    // it to an rvalue object with the values (9:35:10).
    // (8) Declare a unique_ptr to a Timer object (name it uptr2) and initialize
    // it to rvalue object with the values (12:1:6).
    // (9) Declare an object named tt of type Timer and initialize it to the
    // object returned from calling the subtract function passing the objects
    // pointed at uptr1 and uptr2.
    // (10) Display the object contents pointed at by uptr1, and uptr2, and the
    // object tt.

    return 0;
}