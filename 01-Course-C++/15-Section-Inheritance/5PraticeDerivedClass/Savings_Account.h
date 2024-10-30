#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include <iostream>
#include "Account.h"

class Savings_Account: public Account {
    friend std::ostream &operator<< (std::ostream &os, const Savings_Account &account);
protected:
    double int_rate;
public:
    Savings_Account();
    Savings_Account(double balance, double int_rate);
    ~Savings_Account();
    void deposit(double amount);
    //Inheritance of withdraw method is useful for this case.

};

#endif // SAVINGS_ACCOUNT_H
