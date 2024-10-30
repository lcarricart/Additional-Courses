#include <iostream>
#include <climits>

using namespace std;

int main()
{
	//Esto es lo que usualmente podemos ver sin el preprocesing directive <climits>
    cout << "Size of char: " << sizeof(char) << " bytes" << endl;
    
    //Esto es lo que permite ver la librería <climits>:
    cout << "Minimum char value: " << CHAR_MIN << endl;
    
	return 0;
}
