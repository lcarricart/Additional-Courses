#include <iostream>

#include <vector>

using namespace std;

int main()
{
	/*for (inicialization ; condition ; increment) {
         }*/
    
    int scores [] {100, 90, 87};
    
    for (int i {0} ; i < 3 ; i++) {
        cout << scores[i] << endl;
    }
    
    for (int i {1}, j {5} ; i <= 5 ; i++, j++) { //You can use many variables also, as shown.
        cout << i << " * " << j << " : " << (i * j) << endl;
    }
    
    //Really useful:
    vector<int> nums {10, 20, 30, 40, 50};
    
    for (unsigned int i{0}; i < nums.size(); ++i) { //Ese nums.size es muy útil.
        cout << nums[i] << endl;
    //If you don't use the unsigned it works anyway, but the program warns that 
    //there might be an error comparing i (signed) and nums.size (unsigned).
    }
    
	return 0;
}
