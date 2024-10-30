#include <iostream>

using namespace std;

class Base {
public:
    void say_hello() const {
        cout << "Hello - I'm a Base class object" << endl;
    }
};

class Derived: public Base {
public:
    void say_hello() const {
        cout << "Hello - I'm a Derived class object" << endl;
    }
};

void greetings(const Base &obj) {
    cout << "Greetings: ";
    obj.say_hello();
}

int main()
{
	Base b;
    b.say_hello();
    
    Derived d;
    d.say_hello();
    
    greetings(b);
    greetings(d); //This is not recognized as a Derived object, malfunction.
    
    Base *ptr = new Derived();
    
    ptr->say_hello(); //Wrong behavior as well.
    
	return 0;
}
