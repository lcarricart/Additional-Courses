#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <cstring>

using namespace std;

class Mystring
{
    friend std::ostream &operator<< (std::ostream &out, const Mystring &rhs);
    //the std::ostream could be understood like kinda calling the prompt.
    friend std::istream &operator>> (std::istream &in, Mystring &rhs); //No const because I wanna modify.
    
    char *str;
public:
    Mystring();
    Mystring(const char *s);
    Mystring (const Mystring &source);
    Mystring (Mystring &&source); //Remember that this one's for improving the code. Move assignment in case of constant value.
    ~Mystring();
    
    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);
    
    void display() const;
    int get_lenght() const;
    const char *get_str() const;
};

#endif // MYSTRING_H
