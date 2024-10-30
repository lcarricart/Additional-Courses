#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring {
    char *str; //pointer to a char[lenght] that holds a C-style string.
public:
    Mystring(); //No args constructor
    Mystring(const char *s); //Overloaded constructor
    Mystring(const Mystring &source); //Copy constructor
    Mystring(Mystring &&source); //Move constructor
    ~Mystring(); //Destructor
    
    //Overloading the operator (deep copy):
    Mystring &operator=(const Mystring &right_hand_val); //Copy assignment.
    //Overloading the operator (shallow copy):
    Mystring &operator=(Mystring &&right_hand_val); //Move assignment.
    
    void display() const;
    int get_lenght() const;
    const char *get_str() const;

};

#endif // MYSTRING_H
