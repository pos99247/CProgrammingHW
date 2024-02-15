// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40477 C/C++ Programming III
// HW 2

#include <iostream>
#include "Date.h"
using BrianNam::Date;
using std::cout;

int  main()
{
    // Create a date object with default constructor
    Date basic_date;
    cout << "Creating object with defauly constructor: ";
    basic_date.display();

    // Create date objects with invalid month value
    Date wrong_month(0, 2, 2023);
    cout << "With wrong month: ";
    wrong_month.display();

    // Create date objects with invalid day value
    Date wrong_day(2, 30, 2023);
    cout << "With wrong day: ";
    wrong_day.display();

    // Create date objects with invalid year value
    Date wrong_year(1, 2, -10);
    cout << "With wrong year: ";
    wrong_year.display();

    // Create date object with valid date
    Date christmas(12, 25, 2023);
    cout << "With Correct date: ";
    christmas.display();

    // Using accessors with the valid date
    cout << "Month: " << christmas.getMonth() << "\n";
    cout << "Day: " << christmas.getDay() << "\n";
    cout << "Year: " << christmas.getYear() << "\n";
}
