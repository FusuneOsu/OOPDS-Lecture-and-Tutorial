#include <iostream> //
#include <vector>
using namespace std;  //

void odd(int a);
void even(int a);

int main()
{
    int i;
    vector<int> input;
    int counter = 0;

    int sumOdd = 0;
    int sumEven = 0;

    do
    {
        cout << "Type a number: (0 to exit)";
        cin >> i;
        if (i==0)
            break;
        input.push_back(i);
        counter++;
        odd(i);
    } while (i != 0);

    cout << counter << endl;

    //1. Modify the program so that at the end it will display the sum of all ODD and EVEN numbers
    //entered.
    
    for (int i=0; i<counter; i++)
    {
        if ((input[i] % 2) != 0) //sums up the odd numbers
            sumOdd+=input[i];
        else if ((input[i] % 2) == 0) //sums up the even numbers
            sumEven+=input[i];
    }

    cout << "The sum of all odd numbers is: " << sumOdd << endl;

    cout << "The sum of all even numbers is: " << sumEven << endl;

    //2. Modify the program to print out the minimum odd number entered and the maximum EVEN
    //number.

    int Minimum = input[0];
    int Maximum = input[0];

    //This loop will find the minimum odd number
    for (int i = 1; i < counter; ++i)
    {
        if (input[i] < Minimum && (input[i] % 2) != 0 )
            Minimum = input[i];
    }

    //This loop will find the maximum even number
    for (int i = 1; i < counter; ++i)
    {
        if (input[i] > Maximum && (input[i] % 2) == 0)
            Maximum = input[i];
    }

    cout << "The minimum odd number is " << Minimum << endl;
    cout << "The maximum even number is " << Maximum << endl;


    return 0;
}
void odd(int a)
{
    if ((a % 2) != 0)
        {cout << "Number is odd.\n";
        }
    else
        even(a);
    
}
void even(int a)
{
    if ((a % 2) == 0)
        {cout << "Number is even.\n";
        }
    else
        odd(a);
}