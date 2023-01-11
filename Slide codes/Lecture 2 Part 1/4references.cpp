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
    Square &ref = sq1; //Reference is initialized when declared
    ref.setSide(5); //sq1 or ref can be used to refer to the same object
    cout << ref.getSide()
         << endl;
    return 0;
}