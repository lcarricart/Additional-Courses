#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int num {255};
    
    //Diplay using different bases.
    cout << "\n-------------------------------------" << endl;
    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;
    
    //Diplay showing the base prefix for hex and oct.
    cout << "\n-------------------------------------" << endl;
    cout << showbase;
    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;
    
    //Display the hex value in uppercase
    cout << "\n-------------------------------------" << endl;
    cout << showbase << uppercase;
    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;
    
    //Display the + sign in front of positive base 10 numbers.
    cout << "\n-------------------------------------" << endl;
    cout << showpos;
    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;
    
    //Setting using setf method.
    cout.setf(std::ios::showbase);
    cout.setf(std::ios::uppercase);
    cout.setf(std::ios::showpos);
    
    //Reseting to defaults
    cout << resetiosflags(std::ios::basefield);
    cout << resetiosflags(std::ios::showbase);
    cout << resetiosflags(std::ios::showpos);
    cout << resetiosflags(std::ios::uppercase);
    
    cout << "\n-------------------------------------" << endl;
    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;
    
	return 0;
}
