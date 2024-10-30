#include <iostream>

int main() 
{
    int fav;
    
    std::cout << "Please, enter your favourite number from 1 to 100" << std::endl;
    std::cin >> fav;
    std::cout << "Amazing!! That's my favourite number too!" << std::endl;
    std::cout << "No really!! " << fav << " is my favourite number." << std::endl;
    
    return 0;
}