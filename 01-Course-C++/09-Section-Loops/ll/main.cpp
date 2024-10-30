#include <iostream>

using namespace std;

int main()
{
    int sum {0}, i {0};
    
    for (i = 1 ; i < 16 ; i++) {
        sum += i;
    }
    
    cout << sum << endl;
    
	return 0;
}
