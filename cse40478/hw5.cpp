// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40478 C/C++ Programming IV
// HW 4
// hw5.cpp unit test

#include "hw5.h"
#include <iostream>
#include <cassert>

class TestClass 
{
public:
    int value;
    explicit TestClass(int val) : value(val) 
    {}
};

void testAutoPtrConstruction() 
{
    auto_ptr<TestClass> ptr(new TestClass(10));
    assert(ptr.get() != nullptr && ptr->value == 10);
    std::cout << "testAutoPtrConstruction PASSED\n";
}

void testAutoPtrAssignment() 
{
    auto_ptr<TestClass> ptr1(new TestClass(10));
    auto_ptr<TestClass> ptr2;
    ptr2 = ptr1;

    assert(ptr1.get() == nullptr && ptr2.get() != nullptr && ptr2->value == 10);
    std::cout << "testAutoPtrAssignment PASSED\n";
}

void testAutoPtrReleaseAndReset() 
{
    auto_ptr<TestClass> ptr3(new TestClass(10));
    TestClass* ptr4 = ptr3.release();
    assert(ptr3.get() == nullptr && ptr4->value == 10);

    ptr3.reset(new TestClass(20));
    assert(ptr3.get() != nullptr && ptr3->value == 20);
    std::cout << "testAutoPtrReleaseAndReset PASSED\n";

    delete ptr4; // Clean up raw pointer
}

int main() 
{
    testAutoPtrConstruction();
    testAutoPtrAssignment();
    testAutoPtrReleaseAndReset();

    std::cout << "All tests passed.\n";
}
