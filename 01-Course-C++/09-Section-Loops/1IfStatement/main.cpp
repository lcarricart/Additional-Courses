#include <iostream>

using namespace std;

int main()
{
	int num {};
    
    cout << "Enter a number: ";
    cin >> num;
    
    if(num > 10) {
        ++num;
        cout << "Approved";
    }
    else if (num >5) {
        cout << "Partially approved";
    }
    else {
        cout << "Disapproved";
    }
    
	return 0;
}
