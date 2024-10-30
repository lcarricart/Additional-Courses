#include <iostream>

using namespace std;

class Account {
    double balance{0};
public:
    void deposit(double amount) {balance += amount;}
};

class Savings_Account: public Account {
    double some_interest{0};
public:
    void deposit(double amount) { //Redefine a Base class method.
        amount += some_interest;
        Account::deposit(amount); //Invoke a Base class method. 
    }
};

int main()
{
	
    
	return 0;
}
 