#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//Suppose we want to show only positive values and stop when a -99 appears.
    
    vector<int> values {1, 2, -1, 3, -1, -99, 7, 8, 10};
    
    for (auto val: values) {
        if (val == -99)
            break;
        else if (val == -1)
            continue;
             else
                cout << val << endl;
    }
    
	return 0;
}
