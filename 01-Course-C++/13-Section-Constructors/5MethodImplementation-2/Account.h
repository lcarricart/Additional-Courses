#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
//Es una buena practica no agregar el 'using namespace std' porque es un uso innecesario de recursos creo.

class Account {
private:
    //attributes
    std::string name;
    double balance;
    
public:
    //methods below are implemented inside the class.
    void set_balance(double bal) {balance = bal;};
    double get_balance() {return balance;};
    
    //This methods will be declared outside the class declaration
    void set_name(std::string n);
    std::string get_name();
    bool deposit(double ammount);
    bool withdraw(double ammount);
};


#endif // _ACCOUNT_H_
