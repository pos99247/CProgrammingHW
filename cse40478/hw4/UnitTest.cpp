#include "StreamProcessor.h"
#include <sstream>
#include <cassert>
using namespace std;

void testUppercasingSPAFilterToken() {
    istringstream input("");
    ostringstream output;
    UppercasingSPA spa(input, output);

    assert(spa.filterToken("hello") == true);
    cout << "testUppercasingSPAFilterToken PASSED" << '\n';
}

void testUppercasingSPAProcessToken() 
{
    istringstream input("hello world");
    ostringstream output;
    UppercasingSPA spa(input, output);
    spa.process();

    assert(output.str() == "HELLO WORLD ");
    cout << "testUppercasingSPAProcessToken PASSED" << '\n';
}

void testDigitStrippingSPAFilterToken() {
    istringstream input("");
    ostringstream output;
    DigitStrippingSPA spa(input, output);

    assert(spa.filterToken("hello123") == true);
    assert(spa.filterToken("hello") == false);
    cout << "testDigitStrippingSPAFilterToken PASSED" << '\n';
}

void testDigitStrippingSPAProcessToken() 
{
    istringstream input("hello123 world123");
    ostringstream output;
    DigitStrippingSPA spa(input, output);
    spa.process();

    assert(output.str() == "hello world ");
    cout << "testDigitStrippingSPAProcessToken PASSED" << '\n';
}

int main() 
{
    testUppercasingSPAFilterToken();
    testUppercasingSPAProcessToken();
    testDigitStrippingSPAFilterToken();
    testDigitStrippingSPAProcessToken();
}
