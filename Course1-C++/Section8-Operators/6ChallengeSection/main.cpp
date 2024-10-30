#include <iostream>

using namespace std;

int main()
{
    int money {};
    int dollar {};
    short quarter {};
    short dime {};
    short nickel {};
    short penny {};
    
	cout << "Enter the ammount to return in cents: ";
    cin >> money;
    
    dollar = money / 100;
    money -= dollar * 100; //Or money %= 100;
    quarter = money / 25;
    money -= quarter * 25;
    dime = money / 10;
    money -= dime * 10;
    nickel = money / 5;
    money -= nickel * 5;
    penny = money;
    
    cout << "You can provide this change as follows: " << endl;
    cout << "Dollars: " << dollar << endl;
    cout << "Quarters: " << quarter << endl;
    cout << "Dimes: " << dime << endl;
    cout << "Nickels: " << nickel << endl;
    cout << "Pennies: " << penny << endl << endl;
    
	return 0;
}
