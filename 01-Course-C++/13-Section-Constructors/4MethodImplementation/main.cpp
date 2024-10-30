#include <iostream>

using namespace std;

class Account {
private:
    //attributes
    string name;
    double balance;
    
public:
    //methods below are implemented inside the class.
    void set_balance(double bal) {balance = bal;};
    double get_balance() {return balance;};
    
    //This methods will be declared outside the class declaration
    void set_name(string n);
    string get_name();
    bool deposit(double ammount);
    bool withdraw(double ammount);
};

//I'm gonna implement a method outside the class:
void Account::set_name(string n) {
    name = n;
}

string Account::get_name() {
    return name;
}

bool Account::deposit(double ammount) {
    balance += ammount;
    return true;
}

bool Account::withdraw(double ammount) {
    if (balance - ammount >= 0) {
        balance -= ammount;
        return true;
    }
    else {
        return false;
    }
}

int main()
{
	Account frank_account;
    frank_account.set_name("Frank's account");
    frank_account.set_balance(1000.0);
    //Must be done like this because I wrote the program to have balance as private, so I cannot do frank_account.balance = 1000.0;
    
    if (frank_account.deposit(200.0))
        cout << "Deposit OK" << endl;
    else
        cout << "Deposit not allowed" << endl;
        
    if (frank_account.withdraw(500.0))
        cout << "Withdrawal OK" << endl;
    else
        cout << "Not sufficient funds" << endl;
        
    if (frank_account.withdraw(1500.0))
        cout << "Withdrawal OK" << endl;
    else {
        cout << "Not sufficient funds" << endl;
    }
        
    
	return 0;
}
