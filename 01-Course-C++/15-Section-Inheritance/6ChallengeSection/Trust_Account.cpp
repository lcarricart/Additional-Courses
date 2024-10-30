#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    :Savings_Account{name, balance, int_rate}, transactions{0}
{
}

Trust_Account::~Trust_Account()
{
}

bool Trust_Account::deposit(double amount) {
    if (amount >= 5000.0)
        amount += 50.0;
    return Savings_Account::deposit(amount);
};

bool Trust_Account::withdraw(double amount) {
    ++transactions;
    if (transactions < 4) {
        if (amount < (balance * 0.20))
            return Savings_Account::withdraw(amount);
        else
            return false;
    } else
        return false;
    /* This code would work better:
    if ((transactions < 4) || (amount < (balance * 0.20))
        return Savings_Account::withdraw(amount);
    else
        return false;
    */
};

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}