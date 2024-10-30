#include <iostream>

using namespace std;

int main()
{
	//Boolean equality == and inequality !=
    //Sometimes is handy to display "true" instead of a "1". For that purpose we use std::boolalpha;
    
    bool equal {false};
    int num1{}, num2{};
    
    cout << boolalpha; //This is how you change the display.
    
    cout << "Enter two integers separated by a space: ";
    cin >> num1 >> num2;
    equal = (num1 == num2);
    cout << "Equal numbers? " << equal << endl << endl;
    
    //Be careful with precision and type data limits. Errors like this can happen:
    double num3 {12};
    double num4 {11.999999999999999999999999};
    bool equal_double {false};
    
    equal_double = (num3 == num4);
    cout << "For the machine, is 12 equal to 11.9 periodical? " << equal_double << endl << endl;
    /*The reason for this behaviour is that the machine takes an aproximation. Be very careful if
    working for a real life implemented program. Always understand the level of precision we need.*/
    
    //Another curious fact is comparing an integer to a double: An automatic promotion occurs.
    
	return 0;
}
