#include <iostream>
#include <vector>

using namespace std;

/*------------------------------
PROBLEMAS A RESOLVER:
 * Los break me llevan hacia arriba y nunca pregunto si quiero continuar.
 * La media del vector tiene que ser de tipo real, no entero.
--------------------------------*/
int main()
{
    char answer {}, continuation {'Y'};
    vector<int> vec {};
    
	cout << "Welcome to the main menu, please select a letter." << endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl << endl;
   
    while (continuation == 'Y' || continuation == 'y') {
   
        cout << "Enter your choice: ";
        cin >> answer;
        
        switch (answer) {
        
            case 'p' :
            case 'P' : 
                if (vec.size() == 0) {
                    cout << "[] - The list is empty." << endl;
                }
                else {
                    cout << "[";
                    
                    for (auto counter : vec) {
                        cout << " " << counter << " ";
                    };
                    
                    cout << "]" << endl;
                }
                break; //Nunca pregunta si quiero continuar porque el break te lleva arriba parece.
                
            case 'a' :
            case 'A' : {
                int vec_numb {};
                int ammount{};
                
                cout << "How many numbers would you wanna enter?: ";
                cin >> ammount;
                cout << "Enter your " << ammount << " numbers: ";
                for (int i = 0 ; i < ammount ; i++) {
                    cin >> vec_numb;
                    vec.push_back(vec_numb);
                }
                break;                
            }
            
            case 'm' :
            case 'M' : {
                int temp {};
                
                if (vec.size() == 0) {
                    cout << "Unable to calculate the mean." << endl;
                }
                else {
                    for (auto counter : vec) {
                        temp += counter;
                    }
                    
                    temp = temp / vec.size();
                    cout << "The mean is: " << temp << endl;
                }
                break;       
            }
            
            case 's' :
            case 'S' : {
                if (vec.size() == 0) {
                    cout << "There's no data to compare." << endl;
                }
                else { 
                    int minor {vec.at(0)};
                    
                    for (unsigned int i = 1 ; i < vec.size() ; i++) {
                        if (vec.at(i) < minor) {
                                minor = vec.at(i);
                        }
                    }
                    
                    cout << "The minor number is " << minor << endl;
                }
            break;
            }
            
            case 'l' :
            case 'L' : {
                if (vec.size() == 0) {
                    cout << "There's no data to compare." << endl;
                }
                else { 
                    int major {vec.at(0)};
                    
                    for (unsigned int i = 1 ; i < vec.size() ; i++) {
                        if (vec.at(i) > major) {
                                major = vec.at(i);
                        }
                    }
                    
                    cout << "The largest number is " << major << endl;
                }
            break;
            }
            
            case 'q' :
            case 'Q' : {
                cout << "Goodbye" << endl;
                break;
                //Este es el único que no funciona bien pero el flaco de la rta soluciona todo con ifs. No hay switch, un choto.
            }
                
            default : {
                cout << "Not a valid choice." << endl;
                break;
            }
            
        }
        
        do {
            cout << "Would you wanna continue? (Y/N): ";
            cin >> continuation;
            if (continuation != 'Y' && continuation != 'y' && continuation != 'N' && continuation != 'n') {
                cout << "Not a valid option, try again." << endl;
            }
        } while (continuation != 'Y' && continuation != 'y' && continuation != 'N' && continuation != 'n');
    }
	return 0;
}
