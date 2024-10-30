#include <iostream>
#include <string>

using namespace std;

int main()
{
	string message;
    
    cout << "Introduce a group of letter without spaces: ";
    cin >> message;
    
    string pyramid ((2*message.size() - 1), ' ');
    int m {};
    if (message.size() == 1)
        m = 0;
    else 
        m = (message.size() - 1);
        //Parece ilógico, pero como mi mensaje en la piramide queda duplicado y lo necesito impar, este es el medio.
        
    cout << "the middle is " << m << endl;
    
    for (size_t i {0} ; i < message.size() ; i++) {
        for (size_t j {0} ; j <= i ; j++) {
            pyramid.at(m - j) = message.at(i - j);
            pyramid.at(m + j) = message.at(i - j);
        }
        for (char c: pyramid) {
            cout << c;
        }
        cout << endl;
    }
    
	return 0;
}
