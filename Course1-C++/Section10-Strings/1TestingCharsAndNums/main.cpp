#include <iostream>

using namespace std;

int main()
{
	/*
            Testing functions
    True if 'c' is:
    isalnum(c) --> a letter or digit
    isalpha(c) --> a letter
    isdigit(c) --> a digit
    islower(c) --> lowercase letter
    isupper(c) --> uppercase letter
    isprint(c) --> a printable character
    ispunct(c) --> a punctuation character
    isspace(c) --> a whitespace
    */
    
    /*
            Convertion functions
    tolower(c)
    toupper(c)
    */
    
    char my_name[8] {"Frank"}; //This initializes the string and puts a null character at the end.
    my_name[5] = 'l';
    my_name[6] = 'y';
    my_name[7] = 'n'; 
    /*In C++, the last character of a string is a null one; that's the way this programming language understand the end of it.
    That's why when I try to modify position 7, at the time of prinrinm*/
    cout << my_name << endl;
    
    /*
            Functions on #include <cstring>
    Copying
    Concatenation
    Comparison
    Searching
    Others
    */
    
    /*
            Converting functions on #include <cstdlib>
    integer
    float
    long
    [more]
    */
	return 0;
}
