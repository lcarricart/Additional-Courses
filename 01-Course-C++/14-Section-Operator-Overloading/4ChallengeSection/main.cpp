#include <iostream>
#include <cstring>
#include "Mystring.h"

using namespace std;

//The program used to work but dunno if it doesn't because of the compiler or what.

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
    
    b = "george";
    cout << (a == b) << endl; //false
    cout << (a != b) << endl; //true
    cout << (a<b) << endl; //true
    cout << (a>b) << endl; //false
    
    Mystring s1 {"FRANK"};
    s1 = -s1;
    cout << s1 << endl; //frank
    
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
    cout << s << endl; //FRANK
    
    s = -s;
    cout << s << endl; //frank
    
    Mystring result;
    result = ++s;
    cout << s << endl; //FRANK
    cout << result << endl; //FRANK
    
    s = "Frank";
    s++;
    cout << s << endl; //FRANK
    
    s = -s;
    cout << s << endl; //frank
    result = s++; 
    cout << s << endl; //FRANK
    cout << result << endl; //frank
    
	return 0;
}
