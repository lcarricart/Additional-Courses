#include <iostream>

using namespace std;

/*
Inline functions work on assembly code, and they're used for when calling a function takes more and memory than just applying the task inside of it.
In those cases we can suggest the compiler to do it inline, but it can get unefficient code if done unproperly.
Sometimes this is automatically done by compilers, as they're so advanced nowadays, but the concept is just to be able understand a code when this appears.
*/

inline int add_numbers (int a, int b) {
    return a + b;
}

int main()
{
	int result{0};
    result = add_numbers(100,200);
    
	return 0;
}
