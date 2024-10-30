#include <iostream>
#include <string>

using namespace std;

class Account {
public:
    //attributes
    string name {"Account"};
    double balance {0.0};
    
    //methods
    bool deposit(double);
    bool withdraw(double);
};

int main()
{
    Account *frank_account {nullptr};
	frank_account = new Account;
    //Doing the same but using the heap.
    
    //As my variable doesn't have a reference name I use the pointer.
    (*frank_account).balance;
    (*frank_account).deposit(1000.00);
    
    //As the code above is sometimes hard to read, C++ offers an alternative:
    frank_account->balance;
    frank_account->deposit(1000.00);
    
	return 0;
}
