#include <iostream>
#include <cstring>
#include "Mystring.h"

using namespace std;

/*
There's two possible solutions:
- Declare the functions as friends of class and introducing one extra parameter. Changes over some 'const' definitions at declaring.
Also have to declare the <<, >> operators, which is not neccesary the other way.

- Declare the functions inside the class and passing less parameters (because we have the 'this' pointer). Solved using getters.
*/

int main()
{
	
    cout << boolalpha << endl;
    Mystring a {"frank"};
    Mystring b {"frank"};
    
    cout << (a == b) << endl; //true
    cout << (a != b) << endl; //false
    
    /*GREAT! Now I have to define the behaviour of poerator "=" as a move constructor for the case b = "george".
    However, later on I will need to define its behaviour as a copy constructor as well for the case s1 = -s1.
    That last case as a copy constructor is easier to see for the case b = a. You equalize to another object, you copy the data, not loose it.*/
    
    b = "george";
    cout << (a == b) << endl; //false
    cout << (a != b) << endl; //true
    
    //Now I gotta define behaviours for these two boolean operators.
    
    cout << (a<b) << endl; //true
    cout << (a>b) << endl; //false
    
    /*Imma define an operator '-' that will return a Mystring object.
    To practice friendship on non-binary operators, I can do the uppercase case.*/
    
    
    /*Up until this point, the program doesn't work because I haven't defined yet a move and copy constructor.
    Try to understand where am I needing to use them in this lines (or functions involved in this line).*/
    Mystring s1 {"FRANK"};
    s1 = -s1;
    Mystring s11 {"frankenstein"};
    s11 = ++s11;
    
    cout << s1 << endl; //frank
    cout << s11 << endl; //FRANKESTEIN    
    
    s1 = s1 + "******";
    cout << s1 << endl; //frank******
    
    s1 += "------";
    cout << s1 << endl; //frank*****------
    
    Mystring s2{"12345"};
    s1 = s2*3;
    cout << s1 << endl; //123451234512345
    
    Mystring s3{"abcdef"};
    s3 *= 5;
    cout << s3 << endl; //abcdefabcdefabcdefabcdefabcdef
    
    Mystring s = "Frank";
    ++s;
    cout << s << endl; //Frank
    
    s = -s;
    cout << s << endl; //frank
    
    Mystring result;
    result = ++s;
    cout << s << endl; //frank
    cout << result << endl; //FRANK
    
    s = "Frank";
    s++;
    cout << s << endl; //Frank
    
    s = -s;
    cout << s << endl; //frank
    result = s++; 
    cout << s << endl; //FRANK
    cout << result << endl; //frank
    
    //PERFECTO!!
    
	return 0;
}
