#include <iostream>

using namespace std;

int main()
{
	int miles {};
    int gallons {};
    double miles_per_gallon {};
    
    cout << "Enter the miles: ";
    cin >> miles;
    cout << "Enter the gallons: ";
    cin >> gallons;
    
    try {
        if (gallons == 0)
            throw 0;
        //else
        miles_per_gallon = static_cast<double>(miles) / gallons;
        cout  << "Result: " << miles_per_gallon << endl;
    }
    //If I dont implement any catch block, te program would terminate after the 'throw'. But if I catch it I can decide what to do with it.
    //You always wana catch by reference. It catches the exception because it's expecting an integer (our 'zero').
    catch (int &excp) { 
        cerr << "Sorry, I cant divide by zero." << endl;
    }
    
    cout << "Bye." << endl;
    
	return 0;
}
