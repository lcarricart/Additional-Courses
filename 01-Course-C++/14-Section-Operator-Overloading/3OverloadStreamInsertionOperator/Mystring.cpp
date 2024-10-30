#include "Mystring.h"
#include <iostream>
#include <cstring>

using namespace std;

std::ostream &operator<<(std::ostream &out, const Mystring &rhs) {
    out << rhs.str; //or os << obj.get_str(); if not friend of function.
    return out;
}

std::istream &operator>>(std::istream &in, Mystring &rhs) { //the rhs is not const in this case 'cause I wanna modify its data.
    //Lets store the string we are using.
    char *buff = new char [1000]; //a big size so we can store whatever we introduce.
    in >> buff;
    rhs = Mystring{buff}; //if you hace a copy or move assignments implemented correctly, since we have a raw pointer.
    delete[] buff;
    return in;
}

Mystring::Mystring() 
    : str{nullptr} { 
        str = new char[1];
        *str = '\0'; 
    }

Mystring::Mystring(const char *s)
    : str{nullptr} {
        if (s == nullptr) { 
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s) + 1];
            strcpy(str, s);
        }
    }
    
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
        str = new char[std::strlen(source.str) + 1];
        strcpy(str, source.str);
        cout << "Copy constructor used" << endl;
    }
    
Mystring::Mystring(Mystring &&source)
    : str(source.str) {
        source.str = nullptr;
        cout << "Move constructor used" << endl;
    }

Mystring::~Mystring() {
    delete [] str;
}

//Copy assignment
Mystring &Mystring::operator=(const Mystring &right_hand_val) {
    cout << "\nUsing copy assignment" << endl;
    if (this == &right_hand_val) { 
        return *this;
    }
    delete [] str; 
    str = new char[strlen(right_hand_val.str) + 1];
    strcpy(str, right_hand_val.str); 
    return *this; 
}

Mystring &Mystring::operator=(Mystring &&right_hand_val) {
    cout << "\nUsing move assignment" << endl;
    if (this == &right_hand_val)
        return *this;
    delete [] str;
    str = right_hand_val.str;
    right_hand_val.str = nullptr;
    return *this;
}

//Display method
void Mystring::display() const {
    cout << str << " : " << get_lenght() << endl;
}



int Mystring::get_lenght() const { return std::strlen(str); }
