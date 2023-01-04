#include <iostream>
using namespace std;

// int mmin(int x, int y){
//     if (x<y)
//         return x;
//     else
//         return y;
// }
// double mmin (double x, double y){
//     if (x<y)
//         return x;
//     else
//         return y;
// }
// string mmin (string x, string y){
//     if (x<y)
//         return x;
//     else
//         return y;
// }

template<class G>
G mmin(G x, G y){
    if (x<y)
        return x;
    else
        return y;
}
template<class G>
G mmax(G x, G y){
    if (x>y)
        return x;
    else
        return y;
}

struct Pair{
    int x;
    int y;
public:
    bool operator<(const Pair &other){
        return x < other.x;
    }
    bool operator>(const Pair &other){
        return x > other.x;
    }
};

template <class T>
void mySort(T arr[], int size){
    for (int i=0; i<size-1; i++)
    {
        for (int j=i; j<size; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

int main(){
    cout << mmin(9,6) << endl;
    cout << mmin(9.9,6.5) << endl;
    cout << mmin("ABC","BCD") << endl;
    cout << mmin('c','a') << endl;
    
    Pair a{4,5};
    Pair b{5,6};
    Pair d = mmin(a,b);
    cout << d.x << ":" << d.y << endl;
    
    Pair e = mmax(a,b);
    cout << e.x << ":" << e.y << endl;

    int arr[] = {1,2,6,5,4,8,7,0};
    mySort(arr, 8);
    for (auto t:arr)
        cout << t << ":";
    cout << endl;

    Pair parr[] = {{1,2},{6,5},{4,8},{7,0},{3,7}};
    mySort(parr, 7);
    for (auto t:parr)
        cout << t.x << "," << t.y << ":";
    cout << endl;
}