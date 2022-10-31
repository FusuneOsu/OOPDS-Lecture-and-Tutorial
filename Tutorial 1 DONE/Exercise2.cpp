#include <iostream>
#include <algorithm>
using namespace std;

// 1. Add a function “ReadArray ( int a[ ])” to read the elements of the array from the keyboard. Call
// ReadArray from the main function and run the program. The result should be the same.
void ReadArray(int a[])
{
    int counter = 0;
    int inputNum;

    while (counter != 8)
    {
        cout << "Please enter a number" << endl;
        cin >> inputNum;

        a[counter] = inputNum;
        counter++;
    }

    int Minimum = a[0];

    for (int i = 1; i < counter; ++i)
    {
        if (a[i] < Minimum)
            Minimum = a[i];
    }

    cout << "The lowest member value of the array is "
         << Minimum << "." << endl;
}

// 3
void SortAscend(int arr[], int n)
{
    sort(arr, arr + n);
}

void DisplayArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << " " << arr[i];
}

int main()
{
    // The members of the array
    int Numbers[] = {8, 250, 36, 44, 52, 60, 75, 89};
    int Minimum = Numbers[0];
    auto a = 8;

    // Compare the members
    for (int i = 1; i < sizeof(Numbers) / sizeof(int); ++i)
    {
        if (Numbers[i] < Minimum)
            Minimum = Numbers[i];
    }

    // Announce the result
    cout << "The lowest member value of the array is "
         << Minimum << "." << endl;

    // Call the function ReadArray for Question 1
    // ReadArray(Numbers);

    // 2. Modify the program so that it returns the maximum value in the array.
    int Maximum = Numbers[0];
    for (int i = 1; i < sizeof(Numbers) / sizeof(int); ++i)
    {
        if (Numbers[i] > Maximum)
            Maximum = Numbers[i];
    }

    cout << "The highest member value of the array is "
         << Maximum << "." << endl;

    // 3. Add a function to sort the data in ascending order
    int n = sizeof(Numbers) / sizeof(Numbers[0]);
    SortAscend(Numbers, n);

    // 4. Add a function to display the contents of the array.
    DisplayArray(Numbers,n);

    return 0;
}