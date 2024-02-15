// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40477 C/C++ Programming III

#include <iostream>
using std::cout;
using std::cerr;
const int DEFAULT_MONTH = 1;

class Date
{
private:
    int month;
    int day;
    int year;
public:
    Date(int month, int day, int year)
    {
        if (month < 1 || month > 12)     // month can only be [1,12]
        {
            this->month = DEFAULT_MONTH; // set month to 1 if in invalid range
            cerr << "There was an attempt to set an invalid month value.\n";
        }
        else 
        {
            this->month = month;         // access hidden member
        }
        this->day = day;                 // access hidden member
        this->year = year;               // access hidden member
    }
    void setMonth(int month)
    {
        if (month < 1 || month > 12)
        {
            this->month = DEFAULT_MONTH; // set month to 1 if in invalid range
            cerr << "There was an attempt to set an invalid month value.\n";
        }
        else
        {
            this->month = month;         // access hidden member
        }
    }
    int getMonth()
    {
        return month;
    }
    void setDay(int day)
    {
        this->day = day;                 // access hidden member
    }
    int getDay()
    {
        return day;
    }
    void setYear(int year)
    {
        this->year = year;               // access hidden member
    }
    int getYear()
    {
        return year;
    }
    void display()                       // displays the member values
    {
        cout << month << "/" << day << "/" << year << "\n";
    }
};

int main()
{
    // Create a Date object with invalid month
    Date christmas(14, 25, 2023);
    cout << "Creating object with invalid month: ";
    christmas.display();

    // Create a Date object with valid month
    Date independence_day(7, 14, 1944);
    cout << "Initial date: ";
    independence_day.display();

    // Provide a invalid month
    independence_day.setMonth(14);
    cout << "When provided with invalid month: ";
    independence_day.display();

    // Set month
    independence_day.setMonth(8);
    cout << "After setting month to 8: " << independence_day.getMonth() 
        << "\n";

    // Set day
    independence_day.setDay(15);
    cout << "After setting month to 15: " << independence_day.getDay() << "\n";
    
    // Set year
    independence_day.setYear(1945);
    cout << "After setting month to 1945: " << independence_day.getYear() 
        << "\n";
    
    // Display the final
    cout << "Final updated date: ";
    independence_day.display();
}
