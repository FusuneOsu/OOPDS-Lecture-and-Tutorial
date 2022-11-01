#include <iostream>
using namespace std;

int main(){
    int arr[] {1, 2, 4};
    cout << arr << endl;   // name of the array is a constant pointer
                           // a fixed value
    cout << &arr[0] << endl;  // arr = &arr[0] same

    for (int i=0; i<3; i++)
        cout << &arr[i] << endl;

    cout << (&arr[1]-&arr[0])*sizeof(int) << endl;

    cout << *arr << endl;   // prints element 0 of the array
    cout << *(&arr[0]) << endl; // same as the previous line

    // arr = &arr[0]

    int *r;
    r = &arr[0];
    for (int j=0; j<3; j++){
        r = static_cast<int*>(r + j);
        cout << r << " : ";
        cout << *r << endl; 
                                // *(r+0)  , *(r+1), *(r+2)
    }                           // r[0]    , r[1], r[2]
                                // arr[0]  , arr[1], arr[2]
                                // *(arr+0), *(arr+1), *(arr+2)

    r = arr;
    cout << *(r+0) << *(r+1) << *(r+2) << endl;

}