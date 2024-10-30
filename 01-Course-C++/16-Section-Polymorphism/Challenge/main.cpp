#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"

using namespace std;

/*For this example we're creating an "IllegalBalanceException" class for negative values. The implementation is located on the constructor
for a Checking_Account object. It'd be better if I can implement it in the Account constructor, but as I'm'not using smart pointers I
think it doesn't work. */

int main() {
    
    try {
        Checking_Account frank {"Frank", -5000};
        cout << frank << endl;
    }
    catch (const IllegalBalanceException &ex) {
        cerr << "Couldn't create account: negative balance" << endl;
    }
    cout << "Program completed succesfully" << endl;
    
    
    return 0;
}

