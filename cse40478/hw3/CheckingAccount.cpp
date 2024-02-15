// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40478 C/C++ Programming IV
// HW 4
// CheckingAccount.cpp

#include "CheckingAccount.h"
#include <iostream>
#include <list>
#include <vector>
#include "AccountExceptions.h"
#include "BankAccount.h"
#include "Check.h" 
using namespace std;

class CheckingAccount::CheckingAccountImpl
{
public:
    long accountNumber_;
    double balance_;
    string firstName_;
    string lastName_;
    vector<double> deposits_;
    vector<double> withdrawals_;
    list<Check> checks_;
};
