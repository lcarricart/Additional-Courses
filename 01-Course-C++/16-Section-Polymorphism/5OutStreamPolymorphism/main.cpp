#include <iostream>

using namespace std;

/* In order for us to implement the outstream operator, we cant do it as a member function, because it would work this way "obj << os", and
we want it to work as usual "cout << obj". 
*/

class Account {
    friend ostream &operator<<(ostream &os, const Account &acc);
public:
    virtual ~Account() {};
};

//Outside the class
ostream &operator<<(ostream &os, const Account &acc) {
    os << "Account display.";
    return os;
};

class Checking: public Account {
    friend ostream &operator<<(ostream &os, const Checking &acc);
public:
    ~Checking() {};
};

//Outside the class
ostream &operator<<(ostream &os, const Checking &acc) {
    os << "Checking display.";
    return os;
};

class Savings: public Account {
    friend ostream &operator<<(ostream &os, const Savings &acc);
public:
    ~Savings() {};
};

//Outside the class
ostream &operator<<(ostream &os, const Savings &acc) {
    os << "Savings display.";
    return os;
};

class Trust: public Account {
    friend ostream &operator<<(ostream &os, const Trust &acc);
public:
    ~Trust() {};
};

//Outside the class
ostream &operator<<(ostream &os, const Trust &acc) {
    os << "Trust display.";
    return os;
};

int main()
{
	Account a;
    cout << a << endl;
    Checking c;
    cout << c << endl;
    Savings s;
    cout << s << endl;
    Trust t;
    cout << t << endl;
    
    Account *p1 = new Account();
    cout << *p1 << endl;
    Account *p2 = new Checking();
    cout << *p2 << endl;
    
	return 0;
}
