#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

int main()
{
	cout << "\n=========Account=========" << endl;
    Account acc{};
    acc.deposit(2000.0);
    acc.withdraw(500.0);
    cout << endl;
    
    Account *p_acc {nullptr};
    p_acc = new Account{};
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;
    
    cout << "\n==========Savings Account==========" << endl;
    Savings_Account sav_acc {};
    //If you open the debugger with a break here, you can see that this object is already initialized with balance{0} and name{"An Account"} as well.
    sav_acc.deposit(2000.0);
    sav_acc.withdraw(500.0);
    cout << endl;
    
    Savings_Account *p_sav_acc {nullptr};
    p_sav_acc = new Savings_Account {};
    p_sav_acc->deposit(1000.0);
    p_sav_acc->withdraw(500.0);
    delete p_sav_acc;
    
    cout << "\n=========================";    
	return 0;
}
