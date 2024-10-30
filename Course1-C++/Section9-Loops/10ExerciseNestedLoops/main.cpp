#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int result {};
    vector<int> vec {1, 2, 3};
    
    for (unsigned int i1 = 0 ; i1 < vec.size() ; i1++) {
        for (unsigned int i2 = i1 + 1 ; i2 < vec.size() ; i2++){
            result += vec.at(i1) * vec.at(i2);
        }
    }
    
    cout << result << endl;
    
	return 0;
}
