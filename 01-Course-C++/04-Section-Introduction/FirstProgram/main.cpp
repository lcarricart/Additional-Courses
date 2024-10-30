#include <iostream>

int main() 
{    
    int favourite_number;
    
    std::cout << "Enter your favourite number between 1 and 100" << std::endl;
    /* This std::endl 
    me mueve el cursor debajo */
    std::cin >> favourite_number;
    std::cout << "Oh, that's my favourite number too!" << std::endl;
    
    return 0;
}