#include <iostream>
#include <cstdlib>
using namespace std;

void initArray(long arr[], int size)
{
    srand(time(0));
    for (int i=0; i<size; i++){
        long r = rand()%26+97;
        arr[i] = r;
    }
}

void printArray(long arr[], int size){
    for (int i=0; i<size; i++)
        cout << arr[i] << ":";
    cout << endl;
}

long sumArray(long arr[], int size){
    long sum = 0;
    for (int i=0; i<size; i++)
        sum = sum + arr[i];
    return sum;
}

long minArray(long arr[], int size){
    long min = arr[0];
    for (int i=1; i<size; i++)
    {
        if (min > arr[i])
          min = arr[i];
    }
    return min;
}

int main(){
    long a[10];
    initArray(a,10);
    printArray(a,10);
    long sm = sumArray(a,10);
    cout << "SUM = " << sm << endl;
    cout << minArray(a,10) << endl;
}



// #include <iostream>
// #include <cstdlib>
// using namespace std;

// void initArray(int arr[], int size)
// {
//     srand(time(0));
//     for (int i=0; i<10; i++){
//         long r = rand()%26+97;
//         arr[i] = r;
//         cout << char(r) << ":";
//     }
//     cout << endl;
// }


// int main(){
//     long a[10];
    
//     srand(time(0));
//     for (int i=0; i<10; i++){
//         long r = rand()%26+97;
//         a[i] = r;
//         cout << char(r) << ":";
//     }
//     cout << endl;

//     for (int x : a)
//         cout << x << ":";
//     cout << endl;

//     long sum = 0;
//     for (int i=0; i<10; i++)
//         sum = sum + a[i];

//     cout << "SUM = " << sum << endl;
// }