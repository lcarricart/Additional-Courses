#ifndef MYSTRING_H
#define MYSTRING_H
#include <string>

using namespace std;

class Mystring
{
    char *str;
public:
    Mystring();
    Mystring(const char *s);
    Mystring (const Mystring &source);
    Mystring (Mystring &&source);
    ~Mystring();
    
    Mystring &operator=(const Mystring &rhs); //copy assignment
    Mystring &operator=(Mystring &&rhs); //move assignment
    friend std::ostream &operator<<(std::ostream &out, const Mystring &rhs);
    
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    /*I only pass rhs because the operator is already applied to the object in lhs (which turns to be 'this'), so it know about it.
    [That comment applies for a previous case I tried, with member class functions. Now using friendships it works differently].*/
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);
    friend bool operator<(const Mystring &lhs, const Mystring &rhs);
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator-(Mystring &lhs);
    friend Mystring operator+(const Mystring &lhs, const Mystring &chain); //I wouldn't have ever declared 'chain' as an object, but it's the way to solve the problems involved.
    friend Mystring &operator+=(Mystring &lhs, const Mystring &chain);
    friend Mystring operator*(const Mystring &lhs, const int number);
    friend Mystring &operator*=(Mystring &lhs, const int number);
    friend Mystring operator++(Mystring &lhs); //All upper case
    friend Mystring operator++(Mystring &lhs, int); //First upper case. That 'int' makes it post increment.
};

#endif