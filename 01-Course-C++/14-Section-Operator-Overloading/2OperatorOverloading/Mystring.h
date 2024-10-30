#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring
{
    char *str; //pointer to a char[] that holds a C-style string
public:
    Mystring();
    Mystring(const char *s);
    Mystring (const Mystring &source);
    Mystring (Mystring &&source); //Remember that this one's for improving the code. Move assignment in case of constant value.
    ~Mystring();
    
    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);
    
    Mystring operator-() const; //make lowercase.
    //Unary operators take no parameters, binary operators take one parameter.
    Mystring operator+(const Mystring &rhs) const; //concatenate
    bool operator==(const Mystring &rhs) const;
    
    void display() const;
    int get_lenght() const;
    const char *get_str() const;

};

#endif // MYSTRING_H
