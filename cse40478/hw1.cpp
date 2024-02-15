// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40478 C/C++ Programming IV
// HW 1

#include <algorithm>
#include <iostream>
#include <deque>
#include <numeric>
#include <cassert>
#include <vector>
#include <sstream>

using namespace std;

int gen()
{
    static int i = 0;
    return ++i;
}

void testDequeFunctionality()
{
    // Initialize deque
    deque<int> deq;

    // Populate the deque with generate_n
    generate_n(back_inserter(deq), 10, gen);

    // Use accumulate to verify the sum of the values in deque
    int sum = accumulate(deq.begin(), deq.end(), 0);

    // Check for sum and output pass
    assert(sum == 55);
    cout << "testFunctionality PASSED" << '\n';
}

void testStringFunctionality()
{
    // Initialize string
    string str = "abcdefghijklmnopqrstuvxyz";

    // Use transform to make into uppercase
    transform(str.begin(), str.end(), str.begin(), toupper);

    // Check if uppercase and output pass
    assert(str == "ABCDEFGHIJKLMNOPQRSTUVXYZ");
    cout << "testStringFunctionality PASSED" << '\n';
}

void testVectorFunctionality()
{
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // Contain above using vector iterator range constructor
    vector<int> vec(array, array + 10);

    // Use partition to split even and odd
    auto middle = partition(vec.begin(), vec.end(), [](int x)
        {
            return x % 2 == 0;
        });

    // sort each partition
    sort(vec.begin(), middle);
    sort(middle, vec.end());

    // Copy to ostring stream
    ostringstream oss;
    copy(vec.begin(), vec.end(), ostream_iterator<int>(oss, ""));


    // Check if copied correct to oss
    assert(oss.str() == "24681013579");
    cout << "testVectorFunctionality PASSED" << '\n';
}

int main()
{
    testDequeFunctionality();
    testStringFunctionality();
    testVectorFunctionality();
}