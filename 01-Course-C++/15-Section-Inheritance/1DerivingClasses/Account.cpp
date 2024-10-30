#include "Account.h"

Account::Account()
    :balance{0.0}, name{"An account"}{
}

Account::~Account()
{
}

void Account::deposit(double amount) {
    std::cout << amount << " SAR has been deposited to the account." << std::endl;
}

void Account::withdraw(double amount) {
    std::cout << amount << " has been withdraw from the account." << std::endl;
}