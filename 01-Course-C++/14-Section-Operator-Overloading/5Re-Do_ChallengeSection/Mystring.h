#include <iostream>
#include <string>

using namespace std;

class Mystring
{
private:
    char *str; //I dont understand why should I work with pointers in this case, but lets practice it.
public:
    Mystring();
    Mystring(const char *str); //We wanna protect the data.
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();

    //To practice better, we will make the == as a member class function, and =! as a friend global function.
    //Moreover, the next operator will be a non-friend global function, which will have to operate with getter's to access data.
    bool operator==(const Mystring &rhs) const;
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);
    bool operator<(const Mystring &rhs) const;
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);
    //This ones have 'bool' because they'll return a bool result.
    
    //This ones have 'Mystring' because they'll return an object with different characteristics.
    Mystring &operator=(Mystring &&rhs);
    Mystring &operator=(const Mystring &rhs);
    friend Mystring operator-(const Mystring &obj); //lowercase friend of class.
    Mystring operator++(); //uppercase member class.
    friend std::ostream &operator<<(std::ostream &os, const Mystring &obj); //It'll most commonly be a friend as I need it defined for many objects.
    Mystring operator+(const Mystring &lhs);
    friend Mystring operator+=(Mystring &rhs, const Mystring &lhs);
    Mystring operator*(const int);
    friend Mystring &operator*=(Mystring &lhs, const int);
    friend Mystring operator++(Mystring &obj, int); //uppercase friend of class, post increment.
};
