#include <iostream>

using namespace std;

int main()
{
	/*
    Modulo operator works only with integers.
    
    5/10 is zero cause it assumes integer division. For correct result should use casting.
    5.0/10.0
    
    Increment operator ++
    Decrement operator --
    They can be used as prefix or sufix. ++num or num++.
    There're big differences between this two. Let's see an example:
    */
    
    short counter {10};
    short result {0};
    
    cout << "Sufix increment example.\n";
    cout << "Counter: " << counter << endl;
    result = counter++; //At this moment, the adittion is done after taking the result. Interesting behaviour.
    cout << "Counter: " << counter << endl;
    cout << "Result: " << result << endl << endl;
    
    cout << "Prefix increment example.\n";
    cout << "Counter: " << counter << endl;
    result = ++counter;
    cout << "Counter: " << counter << endl;
    cout << "Result: " << result << endl << endl;
    
    //Another interesting example:
    counter = 10;
    result = 0;
    cout << "Extra example.\n";
    cout << "Counter: " << counter << endl;
    result = counter++ + 10; //result is equal to 20. The increment doesn't affect the operation.
    cout << "Counter: " << counter << endl;
    cout << "Result: " << result << endl;
    
    /*Is a bad practice using the increment twice for a variable in the same statement.
    That would look like this: cout << i++ << ++i;. Or: i++ + ++i;*/
    
	return 0;
}
