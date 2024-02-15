// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40478 C/C++ Programming IV
// HW 4
// CheckingAccount.h

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <iosfwd>
#include <string>
using namespace std;
#include "BankAccount.h"  // This must be included due to public inheritance
class Check;

class CheckingAccount : public BankAccount
{
public:
    CheckingAccount(long accountNumber,
        double initialBalance,
        const string &firstName,
        const string &lastName);
    ~CheckingAccount();
    double getBalance() const;
    void depositCheck(const Check &);
    void depositCash(double);
    void withdrawCash(double);
    virtual ostream &print(ostream &) const;
protected:
    void processAccount();
private:
    class CheckingAccountImpl;
    CheckingAccountImpl *pimpl_;

};
ostream &operator<<(ostream &, const CheckingAccount &);
#endif
