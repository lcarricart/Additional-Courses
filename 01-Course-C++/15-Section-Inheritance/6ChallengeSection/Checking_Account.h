#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include "Account.h"

class Checking_Account: public Account 
{
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    static constexpr const double def_balance = 0.0;
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr const double fee = 1.5;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    ~Checking_Account();
    //We inherit the deposit from Account.
    bool withdraw(double amount);
};

#endif // CHECKING_ACCOUNT_H
