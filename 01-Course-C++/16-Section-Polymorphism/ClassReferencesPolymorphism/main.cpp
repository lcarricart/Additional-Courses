#include <iostream>

using namespace std;

/*We can also use Base class references with dynamic polymorphism, which is very useful when passing objects to functions
expecting Base class references.*/

class Account {
public:
    virtual void withdraw(double amount) {
        cout << "In Account::withdraw" << endl;
    }
    virtual ~Account() {cout << "Account:: destructor" << endl;};
};

class Checking: public Account {
public:
    void withdraw(double amount) override{
        cout << "In Checking::withdraw" << endl;
    }
    ~Checking() {cout << "Checking:: destructor" << endl;};
};

class Savings: public Account {
public:
    void withdraw(double amount) override{
        cout << "In Savings::withdraw" << endl;
    }
    ~Savings() {cout << "Savings:: destructor" << endl;};
};

class Trust: public Account {
public:
    void withdraw(double amount) override{
        cout << "In Trust::withdraw" << endl;
    }
    ~Trust() {cout << "Trust:: destructor" << endl;};
};

void do_withdraw(Account &account, double amount) {
    account.withdraw(amount);
}

int main()
{
	Account a;
    Account &ref = a;
    ref.withdraw(1000);
    
    Trust t;
    Account &ref1 = t;
    ref1.withdraw(1000);
    
    Account a1;
    Savings s2;
    Checking c3;
    Trust t4;
    
    do_withdraw(a1, 1000);
    do_withdraw(s2, 1000);
    do_withdraw(c3, 1000);
    do_withdraw(t4, 1000);
    
	return 0;
}
