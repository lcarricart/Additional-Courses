#include <iostream>

using namespace std;

int main()
{
/* 
A double is a float.
A variable's name cannot start with a number.

Theres three ways of initializing variables in C++:
 * int age = 21; --> C-like initialization.
 * int age (21); --> constructor initialization (for object oriented programming)
 * int age {21}; --> C++11 inizialitation syntax, brings many benefits and should get used to it.
An probe example of this benefit is he following: */  
    
    long long people_on_earth  {7'600'000'000}; //Las comillas simples facilitan mi visualización y no afectan.
    //El programa me tira error porque debería usar un long long int.
    
    /*No ocurre lo mismo usando el método clásico de inicialización. Con el viejo caemos en un overflow.
    El programa corre y sitúa un valor incorrecto, bien peligroso.*/
    
    cout << "There're about " << people_on_earth << " people on earth." << endl;
    
    //Otro ejemplo de overflow:
    
    short value1 {30000};
    short value2 {1000};
    short product (value1 * value2);
    //As I gave a short to a big number we got an overflow error. A random value was placed into the variable.
    
    cout << "The product of " << value1 << " and " << value2 << " is " << product << endl;
    
	return 0;
}
