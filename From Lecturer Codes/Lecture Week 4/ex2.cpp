#include <iostream>
using namespace std;
class Square{
    double side;
public:
    Square(){
        cout << "Object is created\n";
        side = 0;
    }

    ~Square(){
        cout << "Object is deleted\n";
    }

    void setSide(int s){
        side = s;
    }

    double getSide(){
        return side;
    }
};

void print(Square s){
    cout << s.getSide() << endl;
}

int main(){
    cout << "Before" << endl;
    {
        Square s;
    }
    cout << "After" << endl;
}