#include "Mystring.h"
#include <iostream>
#include <cstring>

using namespace std;

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
        //cout << "Copy constructor used" << endl;
    }
    
Mystring::Mystring(Mystring &&source)
    : str(source.str) {
        source.str = nullptr;
        //cout << "Move constructor used" << endl;
    }

Mystring::~Mystring() {
    delete [] str;
}

//copy assignment
Mystring &Mystring::operator=(const Mystring &right_hand_val) {
    //cout << "\nUsing copy assignment" << endl;
    if (this == &right_hand_val) { 
        return *this;
    }
    delete [] str; 
    str = new char[strlen(right_hand_val.str) + 1];
    strcpy(str, right_hand_val.str); 
    return *this; 
}

//move assignment
Mystring &Mystring::operator=(Mystring &&right_hand_val) {
    //cout << "\nUsing move assignment" << endl;
    if (this == &right_hand_val)
        return *this;
    delete [] str;
    str = right_hand_val.str;
    right_hand_val.str = nullptr;
    return *this;
}

//extraction operator
std::ostream &operator<<(std::ostream &out, const Mystring &rhs) {
    out << rhs.str;
    return out;
}

bool operator==(const Mystring &lhs, const Mystring &rhs) { //We don't write 'bool Mystring::operator==(...)' because it's not a member of class.
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) != 0);
}

bool operator<(const Mystring &lhs, const Mystring &rhs) { //I'm not complicating the code because the purpose is to learn overloading.
    if (lhs.str[0] < rhs.str[0]) { //I cannot use lhs.str.at(0) because we're refferring to a character (inside an object), not an object.
        return true;
    } else {
        return false;
    }
}

bool operator>(const Mystring &lhs, const Mystring &rhs) {
    if (lhs.str[0] > rhs.str[0]) {
        return true;
    } else {
        return false;
    }
}

Mystring operator-(Mystring &lhs) { //I wanna be able to assign -s without modifying 's'. Useful for: 's2 = -s1'.
    char *temporal = new char[sizeof(lhs.str) + 1]; //+1 for the void character. 
    std::strcpy(temporal, lhs.str);
    Mystring temp {temporal}; //My function need to return a Mystring object. Still don't know if I can define an object directly with heap.
    delete [] temporal;
    for (size_t i=0; i < sizeof(temp.str); i++) {
        temp.str[i] = tolower(lhs.str[i]);
    }
    return temp;
}

Mystring operator+(const Mystring &lhs, const Mystring &chain) { //Don't wanna mofidy my object.
    //Despite of not being possible, solving by 'return (lhs.str + chain)' doesn't return a Mystring object.
    char *temporal = new char[sizeof(lhs.str) + sizeof(chain) + 1];
    std::strcpy(temporal, lhs.str);
    std::strcat(temporal, chain.str); //strcat adds chain to temporal.
    Mystring temp {temporal}; 
    delete [] temporal;
    return temp;
}

Mystring &operator+=(Mystring &lhs, const Mystring &chain) { //Note that in this case I DO wanna modify my lhs.
    lhs = lhs + chain; //That's how you call an already overloaded function.
    return lhs;
}
//For some reason it doesn't work using 'lhs.str = lhs.str + chain.str'. 'Cause it's already defined for objects, not for attributes in object.

Mystring operator*(const Mystring &lhs, const int number) {
    Mystring temp;
    for (int i = 0; i < number; i++) {
        temp += lhs;
    }
    return temp;
}

Mystring &operator*=(Mystring &lhs, const int number) {
    lhs = lhs * number;
    return lhs;
}

Mystring operator++(Mystring &lhs) {
    for (size_t i=0; i < sizeof(lhs.str); i++) {
        lhs.str[i] = toupper(lhs.str[i]);
    }
    return lhs;
}
//No sé por qué pero si intento no modificar 's' en mi main.cpp, este código no funciona.
    /*
    char *temporal = new char[sizeof(lhs.str) + 1];
    std::strcpy(temporal, lhs.str);
    Mystring temp {temporal};
    delete [] temporal;
    for (size_t i=0; i < sizeof(lhs.str); i++) {
        temp.str[i] = toupper(lhs.str[i]);
    }
    return temp;
    */
    
//ME FALTA RESOLVER ESTA PARTE.
Mystring operator++(Mystring &lhs, int) {
    Mystring temp {lhs};
    ++temp;
    return temp;
}