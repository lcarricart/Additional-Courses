#include <iostream>

using namespace std;

int main()
{
	int num1; 
    double num2; //double meaning real.
    
    cout << "Enter an integer: ";
    cin  >> num1;
    cout << "Enter a real number: ";
    cin  >> num2;
    cout << "Integer: " << num1 << "\nReal: " << num2 << endl;
    
	return 0;

/* The very interesting behaviour is when you input "2.2" as an integer.
It ends up taking "2" as integer and "0.2" as real number. Be careful */

/* If you input a string of letters instead, the programs falls into a fail
state. The program takes random values for the variables unless they've been
initialized, tanking that number. */

}
