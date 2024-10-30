#include <iostream>

using namespace std;

int main()
{
	int arrays [5] {30,2};
    arrays [4] = 4;
    
    /*When you initialize one position, the rest are initialized to zero.
    Otherwise I could do it like this: int arrays [5] {};*/
    /*You can also define an array like this:
    int array [] {2,0,0,1}; It will automatically adjust the size.*/
    
    cout << "Index 0: " << arrays[0] << endl;
    cout << "Index 1: " << arrays[1] << endl;
    cout << "Index 2: " << arrays[2] << endl;
    cout << "Index 3: " << arrays[3] << endl;
    cout << "Index 4: " << arrays[4] << endl;
    cout << "Name: " << arrays << endl; 
    cout << endl;
    cout << arrays << endl;
    //Doing this you get the name of the array for the computer, which is the address.
    
     for (int i{0} ; i < 2 ; i++)
        cout << arrays[i] << " ";
	return 0;
}
