// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Trust_Account.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
    
    // Checkings
    
    vector<Checking_Account> ch_accounts;
    ch_accounts.push_back(Checking_Account {} );
    ch_accounts.push_back(Checking_Account {"Lucho"} );
    ch_accounts.push_back(Checking_Account {"Martin", 2000} );
    ch_accounts.push_back(Checking_Account {"Joel", 5000} );
    
    display(ch_accounts);
    deposit(ch_accounts, 1000);
    withdraw(ch_accounts, 2000);
    
    // Trusts
    
    vector<Trust_Account> tr_accounts;
    tr_accounts.push_back(Trust_Account {} );
    tr_accounts.push_back(Trust_Account {"Amani"} );
    tr_accounts.push_back(Trust_Account {"Nacho", 2000} );
    tr_accounts.push_back(Trust_Account {"Georgii", 5000, 5.0} );
    
    display(tr_accounts);
    deposit(tr_accounts, 1000);
    deposit(tr_accounts, 5000);
    withdraw(tr_accounts, 2000);
    withdraw(tr_accounts, 50);
    withdraw(tr_accounts, 1000);
    withdraw(tr_accounts, 700);

    return 0;
}

