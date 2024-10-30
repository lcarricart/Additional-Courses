#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Very silly example only useful for this case. Helps understanding how the parameters works in this methods.
    
	string unformatted_full_name {"StephenHawking"};
    cout << "Unformatted name: " << unformatted_full_name << endl;
    
    string first_name {unformatted_full_name, 0, 7};
    string last_name = unformatted_full_name.substr(7, 7);
    string formatted_full_name = first_name + last_name;
    formatted_full_name.insert(7, " ");
    
    cout << "Formatted name: " << formatted_full_name << endl;
    
    cout << "-------------Second Exercise-------------" << endl;
    
    string journal_entry_1 {"Isaac Newton"};
    string journal_entry_2 {"Leibniz"};
    cout << "Initial information: " << journal_entry_1 << ", " << journal_entry_2 << endl << endl;
    
    //My system only cares about last names.
    journal_entry_1.erase(0, 6);
    
    if (journal_entry_1.at(0) > journal_entry_2.at(0)) //Alphabetic order.
        swap(journal_entry_1, journal_entry_2);
    
    cout << "Final organization: " << endl;
    cout << journal_entry_1 << endl << journal_entry_2 << endl;
    
	return 0;
}
