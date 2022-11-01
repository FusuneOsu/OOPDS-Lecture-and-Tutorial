#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    srand(time(NULL));
    
    //int a[3][2];   // 3 rows and 2 columns
    
    // allocate a 2d array on the heap
    // with 3 rows and 2 columns
    
    int **a;
    a = new int* [3];
    for (int i=0; i<3; i++)
        a[i] = new int[2];

    // from this point the array can be used
    // just like a normal static array


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


    // it is a must to
    // delete and free allocated heap memory
    // for a 2d array
    for (int i=0; i<3; i++)
        delete[] a[i];
    delete[] a;    
}