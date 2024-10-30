#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

using namespace std;

int main() {
    try {
        Account *Larry = new Checking_Account("Larry_Account", -200);
        Larry->withdraw(500);
    }
    catch (const IllegalBalanceException &ex) {
        cerr << ex.what() << endl;
    }
    catch (const InsufficientFundsException &ex) {
        cerr << ex.what() << endl;
    }
    //This side is added to remark that the program still goes on despite of the exception.
    try {
        Account *Moe = new Checking_Account("Moe_Account", 200);
        Moe->withdraw(500);
    }
    catch (const IllegalBalanceException &ex) {
        cerr << ex.what() << endl;
    }
    catch (const InsufficientFundsException &ex) {
        cerr << ex.what() << endl;
    }
    // test your code here
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

