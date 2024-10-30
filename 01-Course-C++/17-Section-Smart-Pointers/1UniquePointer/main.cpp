#include <iostream>
#include <memory>
#include <vector>

using namespace std;

//With smart pointers, we dont have to worry about uninitialized pointers, because at the time of defining unique_pointer, it is already done.

class Test {
private:
    int data;
public:
    Test(): data{0} {cout << "Test constructor (" << data << ")" << endl;};
    Test(int data): data{data} {cout << "Test constructor (" << data << ")" << endl;};
    ~Test() {cout << "Test destructor (" << data << ")" << endl;};
};

int main()
{
    Test *t1 = new Test{100};
    //Im not deleting the pointer to see the behavior of raw pointers.
    
    unique_ptr<Test> t2 {new Test{200}};
    unique_ptr<Test> t3 = make_unique<Test>(300);
    
    unique_ptr<Test> t4;
    //t4 = t2; Not a possible assignment due to the ownership rule on Unique pointers. They can't point the same object.
    t4 = move(t2);
    if(!t2)
        cout << "t2 is nullptr" << endl;
        //t2 is a nullptr because we move the ownership into t4.
    
    /*On the example of the Account class, Checking_Account, and others, I would be able to write this lines:
    
    unique_ptr<Account> s1 = make_unique<Checking_Account>{"Moe", 5000};
    cout << *s1 << endl;    //Will show as a Checking_Account.
    s1->deposit(5000);
    cout << *s1 << endl;
    
    ===============================================================================
    vector<unique_ptr<Account>> accounts;
    accounts.push_back(make_unique<CheckingAccount>{"James", 1000});
    accounts.push_back(make_unique<Savings_Account>{"Billy", 4000, 5.2});
    accounts.push_back(make_unique<Trust_Account>{"Bobby", 5000, 4.5});
    //It's very important to realize that this push_back is not copying information; in the contrary, is creating information with make_unique every time.
    
    [[    for (auto acc:accounts)
            cout << *acc << endl;   //I dereference the pointers.
        //The problem is that this line wont work
    ]]
    
    for (const auto &acc:accounts)
        cour << *acc << endl;
    //By doing it by reference we avoid copying the pointer, which is not allowed. As I'm working with addresses, I use the specifier 'const'.
    
    */
	return 0;
}
