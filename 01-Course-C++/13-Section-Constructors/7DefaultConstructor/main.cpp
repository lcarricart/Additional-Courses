#include <iostream>
#include <string>

using namespace std;

class Account
{
private: 
    string name;
    double balance;
public:
    Account() {
        name = "None";
        balance = 0.0;
    } 
    /*This is what the compiler does automatically when we don't define any constructor. Despite of not having
    any aparent use, the default constructor is of essence to let C++ create the object.
    Although the constructor is defined automatically, it's best practice to do it explicitly.
    
    Another thing to keep in mind is that if we just define a constructor, this default zero case is never defined
    by the compiler, in which case I should define it myself. A common mistake, then, is to ask the compiler to create
    an object by calling the constructor without arguments, resulting in an error for not having defined the default constructor.*/
    
    Account(string name_val, double bal) {
        name = name_val;
        balance = bal;
    }
    
    bool withdraw(double amount);
    bool deposit(double amount);
};

int main()
{
	Account frank_account;
    Account jim_account;
    
    Account *mary_account = new Account;
    delete mary_account;
    
    Account bill_account ("Bill", 15000.0);
    
	return 0;
}
