#include "Savings_Account.h"

Savings_Account::Savings_Account()
    :int_rate{3.0}{
}

Savings_Account::~Savings_Account()
{
}

void Savings_Account::deposit(double amount) {
    std::cout << amount << " SAR has been deposited to the Savings Account." << std::endl;
}

void Savings_Account::withdraw(double amount) {
    std::cout << amount << " has been withdraw from the Savings Account." << std::endl;
}