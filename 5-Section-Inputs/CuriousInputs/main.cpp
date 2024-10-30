#include <iostream>

using namespace std;

int main()
{
	int num1; int num2;
    
    cout << "Enter a first integer.\n";
    cin  >> num1;
    cout << "Enter a second integer.\n";
    cin  >> num2;
    cout << "You entered " << num1 << " and " << num2 << endl;
        
	return 0;
    
/* What's really curious is that if you input "12 30" in the first program interaction,
it automatically takes both values befores asking for the second one. That's how this 
language works.

Understanding this we can write the input like this: cin >> num1 >> num2;*/


}

