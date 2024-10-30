#include "Mystring.h"
#include <cstring>

using namespace std;

//Constructors---------------------------------------

Mystring::Mystring()
    : str{nullptr} {
        str = new char[1];
        *str = '\0'; //Be extremely careful with "" and '', which is for string and character respectively.
        //cout << "No arguments constructor called" << endl;
    }

Mystring::Mystring(const char *s)
    : str{nullptr} {
        if(s == nullptr) {
            str = new char[1];
            *str = '\0';
        }
        str = new char[strlen(s) + 1]; //strlen is part of <cstring>.
        strcpy(str, s);
        //cout << "String constructor called" << endl;
    }

Mystring::~Mystring()
{
    delete [] str;
}

Mystring::Mystring(const Mystring &source) {
    str = nullptr;
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

Mystring::Mystring(Mystring &&source) {
    str = nullptr;
    strcpy(str, source.str);
    delete [] source.str;
}

//Operators-----------------------------

bool Mystring::operator==(const Mystring &rhs) const { //That final 'const' is used only for member functions it seems. Not allowed on the next function.
    return (std::strcmp(this->str, rhs.str) == 0); //Writing str instead of this->str works the same way.
}

bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return !(std::strcmp(lhs.str, rhs.str) == 0);
}

Mystring &Mystring::operator=(Mystring &&rhs){
    if (this == &rhs) {
        return *this;
    }
    //'this' seems to be an address. That's why you can compare it this == &rhs. You can use its information by pointers.
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

Mystring &Mystring::operator=(const Mystring &rhs){
    if (this == &rhs) {
        return *this;
    }
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

bool Mystring::operator<(const Mystring &rhs) const{
    if (std::strcmp(str, rhs.str) > 0) {
        return false;
    }
    return true;
}

bool operator>(const Mystring &lhs, const Mystring &rhs){
    if (std::strcmp(lhs.str, rhs.str) > 0){
        return true;
    }
    return false;
}

Mystring operator-(const Mystring &obj){ //I dont wanna modify obj. Useful in s2 = -s1.
    Mystring temp;
    temp.str = new char[strlen(obj.str) + 1];
    strcpy(temp.str, obj.str);
    for (size_t i=0; i < strlen(temp.str); i++) {
        temp.str[i] = tolower(temp.str[i]);
    }
    return temp.str;
}

/* Or:
Mystring operator-(const Mystring &obj){ //I dont wanna modify obj. Useful in s2 = -s1.
    char *buff = new char[strlen(obj.str) + 1];
    strcpy(buff, obj.str);
    for (size_t i=0; i < strlen(buff); i++) {
        buff[i] = tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}
*/

/*For the member class function case.
Mystring Mystring::operator-() const {
    char *buff = new char[strlen(str) + 1];
    strcpy(buff, str);
    for (size_t i=0; i < strlen(buff); i++) {
        buff[i] = tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}
*/

Mystring Mystring::operator++() {
    Mystring temp;
    temp.str = new char[strlen(str) + 1];
    strcpy(temp.str, str);
    for (size_t i=0; i < strlen(temp.str); i++) {
        temp.str[i] = toupper(temp.str[i]);
    }
    return temp.str;
}

std::ostream &operator<<(std::ostream &os, const Mystring &obj) {
    os << obj.str;
    return os;
}

Mystring Mystring::operator+(const Mystring &lhs) {
    //Mystring temp;
    char *temporal = new char[strlen(str) + strlen(lhs.str) + 1];
    strcpy(temporal, str);
    strcat(temporal, lhs.str);
    Mystring temp {temporal};
    delete[] temporal;
    return temp;
}

Mystring operator+=(Mystring &rhs, const Mystring &lhs) {
    strcat(rhs.str, lhs.str);
    return rhs;
}

/* Possible complex solution. 
Mystring Mystring::operator*(const int n) {
    if (n < 0) {
        cout << "The operation is not possible" << endl;
        return str;
    } else if (n == 0) {
        char *temp = new char[1];
        Mystring temporal {temp};
        delete [] temp;
        temporal.str[0] = '\0';
        return temporal;
    }
    char *temp = new char[strlen(str) + 1];
    strcpy(temp, str);
    for (auto i=0 ; i < n-1 ; i++) { //Until n-1 because str starts with a full string already, so after 3 more, ends up in 4.
        strcat(str, temp);
    }
    delete [] temp;
    return str;
}
*/

Mystring Mystring::operator*(const int n) {
    Mystring temp;
    for (auto i = 0; i < n; i++) {
        temp += *this;
    }
    return temp;
}

Mystring &operator*=(Mystring &lhs, const int n) {
    lhs = lhs * n;
    return lhs;
    /*I wanted to use a 'for' with lhs += lhs; but my '+=' operator works with 'strcat' and doesn't allow to use the same
    object in both sides. I should modify the operator first in that case.*/
}

Mystring operator++(Mystring &obj, int) { //We wanna modify 'this' to be uppercase, but our return is a lowercase temporal object.
    Mystring temporal {obj.str};
    obj = ++obj;
    //Declaring just '++obj;' doesn't work because that increment is not defined to modify my object.
    return temporal;
}