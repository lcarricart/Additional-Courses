#include "Account.h"


Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
}

bool Account::deposit(double amount) {
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

// I can access the information directly as I'm not a friend of class anymore.
void Account::print(ostream &os) const {
    os << "[Account: " << name << ": " << balance << "]";
}

//std::ostream &operator<<(std::ostream &os, const Account &account) {
//    os << "[Account: " << account.name << ": " << account.balance << "]";
//    return os;
//}
