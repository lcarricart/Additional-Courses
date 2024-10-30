#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
	int num {};
    double total {};
    string name {};
    
    string info {"Moe 100 1234.5"};
    istringstream iss{info};
    
    iss >> name >> num >> total;
    
    cout << setw(10) << left << name
         << setw(5) << num
         << setw(10) << total << endl;
    
    cout << "\n----------------------------------" << endl;
    ostringstream oss{};
    oss << setw(10) << left << name
        << setw(5) << num
        << setw(10) << total << endl;
    cout << oss.str() << endl;
    
    cout << "\n Data validation-----------------------" << endl;
    int value{};
    string entry{};
    bool done = false;
    do {
        cout << "Please enter an integer: ";
        cin >> entry;
        istringstream validator {entry};
        if (validator >> value)
        //This is validating the data type.
            done = true;
        else
            cout << "Sorry, that's not an integer" << endl;
        
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        /*discards the input buffer. Basically, if I'd have inserted 12.38 as an 'integer', my program would have taken the number '12' and 
        left the '.38' in the stream. To ignore that data and avoid it getting itself into the next written value, I add this code line. This 
        way I have a clean stream for the next time I read into it.*/
    } while(!done);
    
    cout << "You entered the integer: " << value << endl;
    
	return 0;
}
