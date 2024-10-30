#include <iostream>

using namespace std;

int main()
{
	/*Used for embedded and operative systems, this loops are not frequently used. Although, there're certain examples
    in which make sense to use them. */
    
    /*for (;;)
        cout << "This will print forever" << endl;*/
    
    while (true) {
        char again {};
        cout << "Do you wanna loop again? (Y/N): ";
        cin >> again;
        
        if (again == 'n' || again == 'N') {
            break;
        }
    }
    
    //This is not an ideal code but it shows how the break can be used.
    
	return 0;
}
