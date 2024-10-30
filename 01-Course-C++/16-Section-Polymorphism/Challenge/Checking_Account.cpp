#include "Checking_Account.h"
#include "IllegalBalanceException.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance} {
        if (balance < 0)
            throw IllegalBalanceException();
}

bool Checking_Account::withdraw(double amount) {
    amount += per_check_fee;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

void Checking_Account::print(ostream &os) const {
    os << "[Checking_Account: " << name << ": " << balance  << "]";
}
