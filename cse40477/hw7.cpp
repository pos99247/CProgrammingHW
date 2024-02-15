// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40477 C/C++ Programming III
// HW 7

#include <iostream>
#include <string>
#include <vector>
#include "StringUtility.h"

using namespace std;
using namespace BrianNam;

void printVector(const vector<string>& strings) 
{
    for (int i = 0; i < strings.size(); ++i)
    {
        cout << strings[i] << "\n";
    }
}

int main() 
{
    // Test for join
    vector<string> stringsForJoin = 
    {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    char delimiter = ',';
    StringUtility util;
    string joinedString = util.join(stringsForJoin, delimiter);
    cout << "Joined string: " << joinedString << "\n\n";

    // Test for reverse
    vector<string> stringsForReverse = 
    {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    vector<string> reversedStrings = util.reverse(stringsForReverse);
    cout << "Reversed strings:\n";
    printVector(reversedStrings);
    cout << "\n";

    // Test for combine
    vector<string> left = {"Mr.", "Mrs."};
    vector<string> right = {"Jones", "Smith", "Williams"};
    vector<string> combinedStrings = util.combine(left, right);
    cout << "Combined strings:\n";
    printVector(combinedStrings);
    cout << "\n";

    // Test for leftPad
    vector<string> stringsForLeftPad = 
    {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    char pad = '*';
    vector<string> leftPaddedStrings = util.leftpad(stringsForLeftPad, pad);
    cout << "Left-padded strings:\n";
    printVector(leftPaddedStrings);
    cout << "\n";

    return 0;
}
