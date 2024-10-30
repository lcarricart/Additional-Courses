#include <iostream>

using namespace std;

int main()
{
	/*Type promotion:
    2 * 5.2; --> 2 is promoted to 2.0 */
    
    /*Type demotion:
    int num {0};
    num = 100.2; --> 100.2 is demoted to 100, truncating the value. */
    
    /*Casting. There's two types, clasical C casting and modern C++ casting.
    - Clasical: average = (double)total / count; 
    - Modern: average = static_cast<double>(total) / count; 
    The benefits on applying the modern way are restrictions over the casting, the program makes sure
    that the casting is possible. Doesn't happen on the classical way and can lead to malfunction.*/
    
    int total_amount {100};
    int total_number {8};
    double average {0.0};
    
    average = (double)total_amount / total_number;
    cout << average << endl; // displays 12
    
    average = static_cast<double>(total_amount) / total_number;
    cout << average << endl; // displays 12.5 as expected.
    
	return 0;
}
