#include "Savings_Account.h"

Savings_Account::Savings_Account()
    :Savings_Account(0.0, 0.0) 
    //I'm initializing values for no args constructor. I will use to delegate as well.
    //I could have defined it this way --> :Account(0.0), int_rate(0.0) {}
    { 
        
    }

Savings_Account::Savings_Account(double balance, double int_rate)
    :Account(balance), int_rate(int_rate)
    //I initialize balance directly in my Account object. Otherwise one'd be zero and the other one wouldn't match.
    {
        
    }

void Savings_Account::deposit(double amount) {
    amount = amount + (amount * int_rate/100);
    Account::deposit(amount); //calling the Base method.
}

Savings_Account::~Savings_Account()
{
}

std::ostream &operator<< (std::ostream &os, const Savings_Account &account) {
    os << "Savings Account balance: " << account.balance << " Interest rate: " << account.int_rate;
    return os;
}

