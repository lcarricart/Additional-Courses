#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double num1 {123456789.987654321};
    double num2 {1234.5678};
    double num3 {1234.0};
    
    //Using default settings. For big numbers there will be rather truncation, or forced scientific expression.
    //6 digit of precision, no + signs, no trails of zeros, no uppercase, no scientific notation.
    cout << "Defaults------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    
    cout << setprecision(2);
    cout << "Precision 2----------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    
    cout << setprecision(5);
    cout << "Precision 5----------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    
    cout << setprecision(9);
    cout << "Precision 9----------------------------" << endl;
    cout << num1 << endl; //Rounded value.
    cout << num2 << endl;
    cout << num3 << endl;
    
    //Seting presicion 3 and fixed. We fix the decimal, and the precision applies for the right side.
    cout << setprecision(3) << fixed;
    cout << "Precision 3 - fixed----------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    
    //Seting presicion 3 and scientific notation. It's getting the 'fixed' attribute from before.
    cout << setprecision(3) << scientific << uppercase;
    cout << "Precision 3 - scientific----------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    
    //Show + symbol.
    cout << setprecision(3) << fixed << showpos;
    cout << "Precision 3 - fixed - showpos----------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    
    //Back to defaults. Two different ways of doing it.
    cout.unsetf(std::ios::scientific | std::ios::fixed);
    cout << resetiosflags(std::ios::showpos);
    
    cout << "Precision 10 - showpoint-------------------------" << endl;
    cout << setprecision(10) << showpoint;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    
    //Back to defaults
    cout << "Back to defaults-------------" << endl;
    cout.unsetf(std::ios::scientific | std::ios::fixed | std::ios::uppercase);
    cout << setprecision(6) << resetiosflags(std::ios::showpos) << resetiosflags(std::ios::showpoint);
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    
	return 0;
}
