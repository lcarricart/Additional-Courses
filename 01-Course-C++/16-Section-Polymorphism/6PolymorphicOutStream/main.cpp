#include <iostream>

using namespace std;

class I_Printable {
    //Whenever we write a class name beggining with "I_" it means we're intending it to be an interface. This class is the interface printable.
    //I need the outstream as a friend to use it regularly "cout << obj", and not "obj << os" as a member function.
    friend ostream &operator<<(ostream &os, const I_Printable &obj);
public:
    //Pure virtual function to be implemented by all the derived classes.
    virtual void print(ostream &obj) const = 0;
    virtual ~I_Printable() = default; //That's how you define a virtual destructor.
};

// Outside the class
ostream &operator<<(ostream &os, const I_Printable &obj) {
    obj.print(os);
    return os;
};

class Account: public I_Printable {
public:
    virtual void print(ostream &os) const override {
        os << "Account display.";
    };
    virtual ~Account() {};
};


class Checking: public Account {
public:
    virtual void print(ostream &os) const override {
        os << "Checking display.";
    };
    ~Checking() {};
};

class Savings: public Account {
public:
    virtual void print(ostream &os) const override {
        os << "Savings display.";
    };
    ~Savings() {};
};

class Trust: public Account {
public:
    virtual void print(ostream &os) const override {
        os << "Trust display.";
    };
    ~Trust() {};
};

/* And if we wanna implemment a function "print(*p1)" we can define the following:

void print(const I_Printable &obj) {
    cout << obj << endl;
};

*/

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
