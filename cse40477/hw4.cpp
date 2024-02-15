// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40477 C/C++ Programming III
// HW 4

#include <iostream>
#include "COMPLEX.h"

using namespace std;
using namespace BrianNam;

int main() 
{

    // Test default constructor
    Complex c1;
    cout << "Default Constructor: " << c1 << "\n"; // Should print 0

    // Test parameterized constructor
    Complex c2(3, 4);
    cout << "Parameterized Constructor: " << c2 << "\n"; // Should print 3+4i

    // Test addition
    Complex c3 = c1 + c2;
    cout << "Addition: " << c3 << "\n"; // Should print 3+4i

    // Test subtraction
    Complex c4(1, 1);
    Complex c5 = c2 - c4;
    cout << "Subtraction: " << c5 << "\n"; // Should print 2+3i

    // Test equality
    Complex c6(3, 4);
    if (c2 == c6) 
    {
        cout << "Equality: c2 and c6 are equal.\n";
    }
    else 
    {
        cout << "Equality: c2 and c6 are not equal.\n";
    }

    // Test inequality
    Complex c7(1, 4);
    if (c2 == c7)
    {
        cout << "Equality: c2 and c7 are equal.\n";
    }
    else
    {
        cout << "Equality: c2 and c7 are not equal.\n";
    }

    // Test input
    Complex c8;
    cout << "Enter a complex number in the format (real imaginary): ";
    cin >> c8;
    cout << "You entered: " << c8 << "\n";

    // Test output
    cout << "Testing output: " << c8 << "\n";

    return 0;
}