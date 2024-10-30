#include <iostream>

using namespace std;

/*In this program we will see how exception handling can modify the regular behavior of a code, leading to memoery leaks. The two test
examples are including and removing the exceptions.
If I move the 'try' and 'catch' to func_b, then only func_c will not be closed.*/

void func_b();
void func_c();

void func_a() {
    cout << "Starting func_a." << endl;
    func_b();
    cout << "Ending func_a." << endl;
};

void func_b() {
    cout << "Starting func_b." << endl;
    func_c();
    cout << "Ending func_b." << endl;
};

void func_c() {
    cout << "Starting func_c." << endl;
    throw 100;
    /*When we throw this exception, the compiler looks for the catch instead of ending the functions, and as it is located on the main,
    they all remain open. */
    cout << "Ending func_c." << endl;
};


int main()
{
	cout << "Starting main" << endl;
    try {
        func_a();
    }
    catch (int &ex) {
        cout << "Caught error in main" << endl;
    }
    cout << "Finishing main" << endl;
    
	return 0;
}
