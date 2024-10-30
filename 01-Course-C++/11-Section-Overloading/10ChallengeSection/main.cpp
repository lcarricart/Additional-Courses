#include <iostream>
#include <vector>

using namespace std;

void print_menu();
char enter_choice();
void switch_choice(char, vector<int> &vec);
void display_vector(vector<int> &vec);
void add_number_funct(vector<int> &vec);
void mean_calculator(vector<int> &vec);
void smaller_value(vector<int> &vec);
void larger_value(vector<int> &vec);
void continuation_anti_error(char &continuation);

int main()
{
    char answer{}, continuation{'Y'};
    vector<int> vec{};
    
	print_menu();
    
    while (continuation == 'Y') {
        
        answer = enter_choice();
        switch_choice(answer, vec);
        
        do { //This do while is located inside the while to verify if the sequence should repeat.
            continuation_anti_error(continuation);
        } while (continuation != 'Y' && continuation != 'N');
    }
    
	return 0;
}

void print_menu() {
    cout << "Welcome to the main menu, please select a letter." << endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl << endl;
}

char enter_choice() {
    char answer{0};
    cout << "Enter your choice: ";
    cin >> answer;
    return toupper(answer);
}

void switch_choice(char answer, vector<int> &vec) {
    switch (answer) {
        case 'P':
            display_vector(vec);
        break;
        
        case 'A':
            add_number_funct(vec);
        break;
        
        case 'M':
            mean_calculator(vec);
        break;
        
        case 'S':
            smaller_value(vec);
        break;
        
        case 'L':
            larger_value(vec);
        break;
        
        case 'Q':
             cout << "Goodbye" << endl;
        break;
        
        default:
            cout << "Not a valid choice." << endl;
        break;
    }
}

void display_vector(vector<int> &vec) {
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
}

void add_number_funct(vector<int> &vec) {
    int vec_numb {};
    int ammount{};
                
    cout << "How many numbers would you wanna enter?: ";
    cin >> ammount;
    cout << "Enter your " << ammount << " numbers: ";
    for (int i = 0 ; i < ammount ; i++) {
        cin >> vec_numb;
        vec.push_back(vec_numb);
    }            
}

void mean_calculator(vector<int> &vec) {
    static int temp {};
    
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
}

void smaller_value(vector<int> &vec) {
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
}

void larger_value(vector<int> &vec) {
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
}

void continuation_anti_error(char &continuation) {
    cout << "Would you wanna continue? (Y/N): ";
    cin >> continuation;
    continuation = toupper(continuation);
    if (continuation != 'Y' && continuation != 'N') {
        cout << "Not a valid option, try again." << endl;
    }
}