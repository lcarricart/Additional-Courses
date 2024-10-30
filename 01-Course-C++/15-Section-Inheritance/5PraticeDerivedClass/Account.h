#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

class Account
{
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
private:
    static constexpr const double def_balance = 0.0; 
    //This is useful in case we want to have de default value defined here, instead of repeating it in every function I want it.
protected:
    double balance;
public:
    Account();
    Account(double balance);
    ~Account();
    void deposit(double amount);
    void withdraw(double amount);

};

#endif // ACCOUNT_H
