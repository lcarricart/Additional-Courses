#include <iostream>

using namespace std;

int main()
{
	//A good practice is to not nest conditional operators as if else statements, cause it becomes unreadable.
    //Example: result = (a > b) ? (a - b) : (b - a); Si el resultado es verdadero devuelve (a - b); si es negativo (b - a).
    
    int num{};
    char answer {'Y'};
    
    while (answer == 'Y' || answer == 'y') {
        cout << "Enter an integer: ";
        cin >> num;
    
        cout << num << " is " << ((num %2 == 0) ? "even" : "odd") << endl;
        
        cout << "Would you wanna continue? (Y/N) ";
        cin >> answer;
    }
    
    /*
    
    Also I can use the do while like this:
    
    do {
        statements;
    } while (expression);
    
    */
    
	return 0;
}
