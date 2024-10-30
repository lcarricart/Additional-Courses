#include <iostream>

using namespace std;

int main()
{
    short small_rooms {0};
    short large_rooms {0};
    const short price_small {25};
    const short price_large {35};
    
    cout << "Welcome to Carpet's cleaning service";
    cout << "\nHow many small rooms would you like cleaned? ";
    cin >> small_rooms;
    cout << "How many large rooms would you like cleaned? ";
    cin >> large_rooms;
    
    int total_relative {0};
    float tax {0};
    float total_absolute {0};
    total_relative = ((small_rooms * price_small) + (large_rooms * price_large));
    tax = total_relative * 0.06;
    total_absolute = total_relative + tax;
    
    cout << "==============================";
    cout << "\nEstimate for carpet cleaning service:" << "\nNumber of small rooms: " << small_rooms;
    cout << "\nNumber of large rooms: " << large_rooms << "\nPrice per small room: $" << price_small;
    cout << "\nPrice per large room: $" << price_large << "\nCost: $" << total_relative << "\nTax: $";
    cout << tax << "\n==============================" << "\nTotal estimate: $" << total_absolute;
    cout << "\nThis estimate is valid for 30 days.\n";
    
	return 0;
}
