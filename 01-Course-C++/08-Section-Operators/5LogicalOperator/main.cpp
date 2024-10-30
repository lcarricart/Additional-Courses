#include <iostream>

using namespace std;

int main()
{
	/*
    Precedence rules: 'not' has higher precedence than 'and', 'and' higher than 'or' 
    
    We can use the key-word like syntax or symbol one for logical operators:
    -not --> !
    -and --> &&
    -or --> ||
    Using key word syntax is very weird to see in programs.
    
    For the operator not, when A = true, then not(A) = false.
    */
    
    //Exercise: determine if an entered integer is outside two other integers (contrary of between)
    int boundarie1 {5};
    int boundarie2 {10};
    int num {};
    bool result {false};
    cout << boolalpha;
    
    cout << "Introduce a number to see if it's outside " << boundarie1 << " and " << boundarie2 << " limits: ";
    cin >> num;
    result = (num < boundarie1 || num > boundarie2);
    cout << result;
    
	return 0;
}
