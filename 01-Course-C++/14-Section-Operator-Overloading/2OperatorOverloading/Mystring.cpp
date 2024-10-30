#include "Mystring.h"
#include <iostream>
#include <cstring>

using namespace std;

//Equality
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0); //compare works a certain way that I have to add the '== 0'.
}

//Make lower case
Mystring Mystring::operator-() const {
     char *buff = new char[std::strlen(str) + 1];
     std::strcpy(buff, str);
    for (size_t i=0; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

//Concatenate
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete[] buff;
    return temp;
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
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
    }
    
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
        str = new char[strlen(source.str) + 1];
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



int Mystring::get_lenght() const { return strlen(str); }
