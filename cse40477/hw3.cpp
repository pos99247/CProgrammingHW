// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40477 C/C++ Programming III
// HW 3

#include <iostream>
using std::cout;

#include "SavingsAccount.h"
using BrianNam::SavingsAccount;

int main()
{
    // set correct account balance
    SavingsAccount account1(100);
    cout << "Account1 balance: " << account1.getSavingsBalance() << "\n";

    // set invalid account balance
    SavingsAccount account2(-1.2);
    cout << "Account2 balance after error: " << 
        account2.getSavingsBalance() << "\n";

    // set correct annual interest rate
    SavingsAccount::setAnnualInterestRate(0.05);
    cout << "Annual interest is set to 5%.\n";

    // apply monthly interest rate to account
    account1.applyMonthlyInterest();
    cout << "After applying monthly interest rate, balance: " << 
        account1.getSavingsBalance() << "\n";

    // set invalid annual interest rate
    SavingsAccount::setAnnualInterestRate(-0.05);
    cout << "Trying to set annual interest rate to -5%.\n";

    // check if the annual interest rate has been set to 0
    account1.applyMonthlyInterest();
    cout << "After applying monthly interest rate again, balance: " <<
        account1.getSavingsBalance() << "\n";
}
