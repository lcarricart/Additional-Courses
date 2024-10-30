#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "noboolalpha - default (10 == 10): " << (10 == 10) << endl;
    cout << "noboolalpha - default (10 == 20): " << (10 == 20) << endl;
    
    //Set to true/false formatting. Setting still stays for future boolean insertions.
    cout << boolalpha;
    //method style would be:
    //cout.setf(boolalpha);     std::cout.setf(std::ios::boolalpha);
    cout << "boolalpha (10 == 10): " << (10 == 10) << endl;
    cout << "boolalpha (10 == 20): " << (10 == 20) << endl;
    
    //Toggle to 0/1
    cout << noboolalpha;
    cout << "noboolalpha (10 == 10): " << (10 == 10) << endl;
    cout << "noboolalpha (10 == 20): " << (10 == 20) << endl;
    
    //Resets to default (nonboolalpha)
    cout << std::resetiosflags(std::ios::boolalpha); //Note that we're not telling it to set up boolalpha, it's just the way it's to be written.
    cout << "Default (10 == 10): " << (10 == 10) << endl;
    cout << "Default (10 == 20): " << (10 == 20) << endl;
    
	return 0;
}
