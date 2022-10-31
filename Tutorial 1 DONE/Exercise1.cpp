#include <iostream>
#include <cstdlib>
//#include <stdlib.h>

using namespace std;

int main()
{
    int i, iInt;
    char a, aChar;
    long g;
    float f;
    double d, dDouble;

    // Assign values
    i = 65;
    a = 'r';
    g = 241;
    f = 2.06f;
    d = 122.448;

    /*
    1. Compile and run the program and observe the values printed.

    2. Change all the old casting statements to the new casting format, then compile and
    run the program. Follow this style in casting your expressions from now on.

    ---------------------------------------------------------------------------------------

    Output:
    The integer 65 converted to a character is A
    The character r converted to an integer is 114
    The long integer 241 converted to a character is ±
    The float value 2.06 converted to an integer is 2
    The double value 122.448 converted to a character is z


    The long integer 241 +  the integer 65 converted to an integer is 306
    The long integer 241 +  the integer 65 converted to a character is 2
    The integer 65 +  the character r converted to an integer is -77
    The integer 65 +  the character r converted to a character is │
    The integer 65 *  the character r converted to an integer is 13959.1
    The double 122.448 /  the character r converted to an integer is 1
    The double 122.448 +  the long integer 241 converted to an integer is 363
    
    */

    cout << "The integer " << i << " converted to a character "
         << "is " << static_cast<char>(i) << "\n";

    cout << "The character " << a << " converted to an integer "
         << "is " << static_cast<int>(a) << "\n";

    cout << "The long integer " << g << " converted to a character "
         << "is " << static_cast<char>(g) << "\n";

    cout << "The float value " << f << " converted to an integer "
         << "is " << static_cast<int>(f) << "\n";

    cout << "The double value " << d << " converted to a character "
         << "is " << static_cast<char>(d) << "\n";

    cout << "\n\n";
    iInt = g + i;
    aChar = i + a;
    dDouble = d + g;

    cout << "The long integer " << g << " + "
         << " the integer "
         << i << " converted to an integer "
         << "is "
         << static_cast<int>(iInt) << "\n";

    cout << "The long integer " << g << " + "
         << " the integer "
         << i << " converted to a character "
         << "is "
         << static_cast<char>(iInt) << "\n";

    cout << "The integer " << i << " + "
         << " the character "
         << a << " converted to an integer "
         << "is "
         << static_cast<int>(aChar) << "\n";

    cout << "The integer " << i << " + "
         << " the character "
         << a << " converted to a character "
         << "is "
         << static_cast<char>(aChar) << "\n";

    cout << "The integer " << i << " * "
         << " the character "
         << a << " converted to an integer "
         << "is "
         << static_cast<double>(d * a) << "\n";

    cout << "The double " << d << " / "
         << " the character "
         << a << " converted to an integer "
         << "is "
         << static_cast<int>(d / a) << "\n";

    cout << "The double " << d << " + "
         << " the long integer "
         << g << " converted to an integer "
         << "is "
         << static_cast<int>(dDouble) << "\n";

    cout << "\n\n";

    return 0;
}