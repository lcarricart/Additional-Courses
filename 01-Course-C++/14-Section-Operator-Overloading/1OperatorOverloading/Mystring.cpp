#include "Mystring.h"
#include <cstring>
#include <iostream>

using namespace std;

Mystring::Mystring() //Constructor (no arguments case)
    : str{nullptr} { //No pointer assigned
        str = new char[1];
        *str = '\0'; //Contains null value
    }

Mystring::Mystring(const char *s)
    : str{nullptr} {
        if (s == nullptr) { //If we receive a null:
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
    if (this == &right_hand_val) { //If 'this' is the same object as 'val'.
        //We wanna make sure we're not assigning to the same pointer. Remember 'this' is the pointer to the current object.
        return *this;
    }
    delete [] str; //As the purpose of this function is to assign a new value, first we need to delete the previous information stored.
    str = new char[strlen(right_hand_val.str) + 1]; //We set the size.
    strcpy(str, right_hand_val.str); //Assigning the value.
    return *this; //'this' is str.
}

//Move assignment
Mystring &Mystring::operator=(Mystring &&right_hand_val) {
    cout << "\nUsing move assignment" << endl;
    if (this == &right_hand_val)
        return *this;
    delete [] str;
    str = right_hand_val.str;
    right_hand_val.str = nullptr;
    return *this;
}

void Mystring::display() const {
    cout << str << " : " << get_lenght() << endl;
}

int Mystring::get_lenght() const { return strlen(str); }

const char *Mystring::get_str() const { return str;}

