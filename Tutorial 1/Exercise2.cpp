#include <iostream>
using namespace std;
int main()

{
    // The members of the array
    int Numbers[ ] = {8, 25, 36, 44, 52, 60, 75, 89};
    int Minimum = Numbers[0];
    auto a = 8;

    // Compare the members
    for (int i = 1; i < a; ++i) 
    {
        if (Numbers[i] < Minimum)
        Minimum = Numbers[i];

    }
    
    // Announce the result
    cout << "The lowest member value of the array is "
    << Minimum << "." << endl;
    return 0;
}