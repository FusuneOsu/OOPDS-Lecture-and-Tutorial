#include <iostream>
using namespace std;

// // pass by value function
// void myswap(int x, int y){
//     int temp = x;
//     x = y;
//     y = temp;
// }

void myswap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// pass by reference clashes with the 
// pass by value function
void myswap(int& x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int x = 10, y = 20;

    cout << x << ":" << y << endl;
    myswap(&x, &y);
    cout << x << ":" << y << endl;

    cout << x << ":" << y << endl;
    myswap(x, y);
    cout << x << ":" << y << endl;

}