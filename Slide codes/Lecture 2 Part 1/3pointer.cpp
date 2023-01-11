#include <iostream>
using namespace std;
class Square
{
private:
    int side;

public:
    void setSide(int s)
    {
        side = s;
    }
    int getSide()
    {
        return side;
    }
};

int main()
{
    Square sq1;
    Square *sptr;
    sptr = &sq1;

    //method 1
    // sptr->setSide(5);
    // cout << sptr->getSide()
    //     << endl;

    //method 2
    (*sptr).setSide(5);
    cout << (*sptr).getSide() << endl;

    //method 1 and 2 are equal
    
    return 0;
}