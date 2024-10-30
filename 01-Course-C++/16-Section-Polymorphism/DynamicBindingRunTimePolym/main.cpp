#include <iostream>
#include <vector>

using namespace std;

/*Now we will focus on the real matter of this unit, run-time polymorphism or dynamic binding.
There's two ways to do it: by using base class pointers // or // by using base class references.
In this example I'm using pointers to the bass class.

To make this happen we just gotta add the prefix "virtual" to the function in the Base class. It's not necessary to re-specify this prefix
in the following derived classes, but it's considered best practice. Moreover, functios on the derived classes must have the same type and
specifiers than the first virtual one; otherwise it'll be considered as a redefinition. This could make life very complicated at the time
of seeking for the mistake, so C++ gives the option to specify when are we trying to override a function.
Example:
    [Base] virtual void say_hello() const;
    [Derived] virtual void say_hello();     !! Missing the "const" at the end.
To avoid this mistake we add the signature "override" at the end, so it'll double check.
    [Derived] virtual void say_hello() const override;

It's very important to note that whenever we have a virtual function we gotta have virtual destructors as well, because it could happen that
we destroy a Base class object side before destroying its derived side, not following the right order for destruction on inheritance. This
could happen by deallocating pointers.
*/

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


int main()
{
	cout << "\n===========Pointers=============" << endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();
    
    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);
    
    cout << "\n=====Array======" << endl;
    Account *array[] {p1,p2,p3,p4};
    for (auto i=0; i<4; i++)
        array[i]->withdraw(1000);
        
    cout << "\n=====Vector=======" << endl;
    vector<Account *> accounts{p1,p2,p3,p4};
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw(1000);
        
    cout << "\n======Clean up========" << endl;
    //Before applying virtual destructors, all Account destructors were called, not the specific ones.
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    
	return 0;
}
