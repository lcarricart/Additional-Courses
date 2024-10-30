#include <iostream>
#include <memory>

using namespace std;

class Test {
private:
    int data;
public:
    Test(): data{0} {cout << "\tTest constructor (" << data << ")" << endl;};
    Test(int data): data{data} {cout << "\tTest constructor (" << data << ")" << endl;};
    int get_data() const {return data;};
    ~Test() {cout << "\tTest destructor (" << data << ")" << endl;};
};

void my_deleter(Test *ptr) { //We pass the raw pointer that's being managed, linked to the smart pointer in our case.
    cout << "\tUsing my custom function deleter" << endl;
    delete ptr;
};

int main()
{
	{
        shared_ptr<Test> ptr1 (new Test{100}, my_deleter); //We can't use make_shared in this format.
    } //This parenthesis defines the scope of the variable.
    
    cout << "============================" << endl;
    
    shared_ptr<Test> ptr2 (new Test{1000},
        [] (Test *ptr) {
            cout << "\tUsing my custom lambda deleter" << endl;
            delete ptr;
    });
    //Lambda expressions are so comfortable to see straight away what's happening when reading the code.
    
	return 0;
}
