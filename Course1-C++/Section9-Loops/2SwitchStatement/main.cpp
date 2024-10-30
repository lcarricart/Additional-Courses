#include <iostream>

using namespace std;

int main()
{
	short selection {};
    
    cout << "Choose a number from 1-3 to access different menus: ";
    cin >> selection;
    
    switch (selection) {
        case 1 : cout << "1 selected";
            break;
        case 2 : cout << "2 selected"; //Case 2 relates to "selection" value = 2.
            break;
        case 3 : 
        case 4 : cout << "3 or 4 selected";
            break;
        //This is an interesting behaviour because it's like having an OR operator.
        default: cout << "1, 2, 3, 4 NOT selected";
    }
    /*If we don't use the breaks the code keeps on going until it finds a break statement.
    So if you'd press 1 it would show "1 selected" "2 selected" and continuing until a break.
    That explains what happens when we press 3 in this program.*/
    
    /*
    Not breaking is really useful for the followinf example:
    switch(sentence) {
        case 'd' : 
        case 'D' : cout << "Letter D";
            break;
    }
    */
    
	return 0;
}
