// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40477 C/C++ Programming III
// HW 5

#include <iostream>
#include "SHAPES.h"

using namespace std;
using namespace BrianNam;

const int NUM_OF_SHAPES = 4;

int main()
{
    Shape *shapes[NUM_OF_SHAPES];
    shapes[0] = new Circle(2);
    shapes[1] = new Square(3);
    shapes[2] = new Sphere(4);
    shapes[3] = new Cube(5);

    for (int i = 0; i < NUM_OF_SHAPES; ++i)
    {
        shapes[i]->display();
    }

    for (int i = 0; i < NUM_OF_SHAPES; ++i)
    {
        delete shapes[i];
    }

    return 0;
}