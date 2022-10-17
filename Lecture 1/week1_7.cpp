#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "how many elements :";
    cin >> n;

    // n will only be known after running
    // the program.
    // int arr[n];   // wrong because n is not 
                     // initialized and might
                     // be a big number

    int *arr = new int[n];

    for (int i=0; i<n; i++)
    {
        cout << "enter value " << i+1 << " :";
        cin >> arr[i];
    }

   for (int i=0; i<n; i++)
        cout << arr[i] << endl;

    delete[] arr;
}