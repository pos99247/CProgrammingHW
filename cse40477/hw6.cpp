// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40477 C/C++ Programming III
// HW 6

#include "Array.h"
#include <iostream>

using namespace std;

int main()
{
    BrianNam::Array<int, 5> arrayOfFiveInts;

    // Modify all of the elements
    for (int i = 0; i < 5; ++i)
    {
        arrayOfFiveInts[i] = i * i;
    }

    // Output all of the elements
    for (int i = 0; i < 5; ++i)
    {
        cout << arrayOfFiveInts[i] << " ";
    }
    cout << "\n";

    // Create a const Array from another Array using the copy constructor
    const BrianNam::Array<int, 5> constArrayOfFiveInts = arrayOfFiveInts;

    // Assign an Array to an existing Array using the copy assignment operator
    BrianNam::Array<int, 5> anotherArrayOfFiveInts;
    anotherArrayOfFiveInts = arrayOfFiveInts;

    // Compare two Arrays using the equality operator
    if (arrayOfFiveInts == anotherArrayOfFiveInts)
    {
        cout << "Arrays are equal.\n";
    }

    // Compare two Arrays using the inequality operator
    anotherArrayOfFiveInts[0] = 99;
    if (arrayOfFiveInts != anotherArrayOfFiveInts)
    {
        cout << "Arrays are not equal.\n";
    }

    // Demonstrate an invalid_argument exception being thrown and caught
    try
    {
        arrayOfFiveInts[-1] = 10;
    }
    catch (const invalid_argument& e)
    {
        cout << "Caught exception: " << e.what() << "\n";
    }

    try
    {
        arrayOfFiveInts[5] = 10;
    }
    catch (const invalid_argument& e)
    {
        cout << "Caught exception: " << e.what() << "\n";
    }

    try
    {
        cout << constArrayOfFiveInts[-1] << "\n";
    }
    catch (const invalid_argument& e)
    {
        cout << "Caught exception: " << e.what() << "\n";
    }

    try
    {
        cout << constArrayOfFiveInts[5] << "\n";
    }
    catch (const invalid_argument& e)
    {
        cout << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}