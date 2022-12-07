#include <iostream>
using namespace std;
class Square{
    double side;
public:
    Square(){
        cout << "Object is created\n";
        side = 0;
    }

    Square(const Square &other){
        side = other.side;
        cout << "Copy constructor\n";
    }

    ~Square(){
        cout << "Object is deleted\n";
    }

    void setSide(int s){
        side = s;
    }

    double getSide() const {
        return side;
    }
};

// creates a new object
void print(const Square s){
    cout << s.getSide() << endl;
}

// void print(const Square &s){
//     cout << s.getSide() << endl;
// }

int main(){
    Square s;
    cout << "Before" << endl;
    print (s);
    cout << "After" << endl;
    cout << s.getSide() << endl;
}