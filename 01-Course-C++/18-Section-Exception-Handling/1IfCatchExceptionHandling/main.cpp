#include <iostream>

using namespace std;

/*In this program you can test different cases like:
-Integer divided by 0. [Crash]
-Double divided by 0. [Infinite]
-0 divided by 0. [Nan. Not a number]
*/

int main()
{
	int miles {};
    int gallons {};
    double miles_per_gallon {};
    
    cout << "Enter the miles: ";
    cin >> miles;
    cout << "Enter the gallons: ";
    cin >> gallons;
    
    //miles_per_gallon = miles / gallons; It's gonna truncate the decimal part, as none of the operands are double.
    
    if (gallons != 0) {
        miles_per_gallon = static_cast<double>(miles) / gallons; //Making one of them double is enough.
        cout  << "Result: " << miles_per_gallon << endl;
    } else {
        cerr << "Sorry, I cant divide by zero." << endl;
    }
    
    cout << "Bye." << endl;
    
	return 0;
}
