#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    srand(time(NULL));
    int a[3][2];   // 3 rows and 2 columns

    // a[0][0], a[0][1]
    // a[1][0], a[1][1]
    // a[2][0], a[2][1]

    for (int row=0; row<3; row++){
        for (int col=0; col<2; col++){
            a[row][col] = rand()%10;
        }
    }


    for (int row=0; row<3; row++){
        for (int col=0; col<2; col++){
            a[row][col]*=10;
        }
    }

    for (int row=0; row<3; row++){
        for (int col=0; col<2; col++){
            cout << a[row][col] << " : ";
        }
        cout << endl;
    }
    
}