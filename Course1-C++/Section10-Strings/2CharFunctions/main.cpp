#include <iostream>
#include <cstring> //for c-style string functions
#include <cctype> //for character-based functions

using namespace std;

int main()
{
	char name[20] {};
    char surname[20] {};
    char full_name[50] {};
    char temp[50] {}; 
    
    cout << "Please enter your first name: ";
    cin >> name;
    cout << "Please enter your surname: ";
    cin >> surname;
    cout << "----------------------------------" << endl;
    cout << "Hello " << name << ", your first name has " << strlen(name) << " characters." << endl;
    cout << "Your surname, " << surname << ", has " << strlen(surname) << " characters." << endl;
    
    //Now we are gonna manipulate the string in order to get a full understanding of this null character.
    strcpy(full_name, name); //copies name into full_name. full_name ends up being [L u c i a n o\0]
    strcat(full_name, " "); //concatenates. full_name now is [L u c i a n o \0]
    strcat(full_name, surname); //full_name now is [L u c i a n o  C a r r i c a r t\0]
    
    cout << "Enter your full name: ";
    //cin >> full_name; If I'd write it like this, it wouldn't get my surname as I'm typing a space in the middle.
    cin.ignore(); //This is VERY important because the cin.getline is taking the 'new line' character as input.
    cin.getline(full_name, 50); /*will stop when reaching 50 or pressing enter. I think this one doesn't store
    the extra value in another variable.*/
    
    cout << "---------------------" << endl;
    strcpy(temp, full_name);
    if (strcmp(temp, full_name) == 0)
        cout << temp << " and " << full_name << " are the same" << endl;
    else
        cout << temp << " and " << full_name << " are different" << endl;
    cout << "----------------------" << endl;
    
    for (size_t i{0}; i < strlen(full_name); ++i) { //That 'size_t' is the best way to put 'unsigned', because it limits many possible errors.
        if (isalpha(full_name[i]))
            full_name[i] = toupper(full_name[i]);
    }
    cout << "Your full name is " << full_name << endl;
    
    cout << "---------------------" << endl;
    if (strcmp(temp, full_name) == 0)
        cout << temp << " and " << full_name << " are the same" << endl;
    else
        cout << temp << " and " << full_name << " are different" << endl;
    cout << "----------------------" << endl;
    
	return 0;
}
