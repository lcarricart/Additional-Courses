#include <iostream>

using namespace std;

class Base {
private:
    int value;
public: 
    Base() : value{0} {};
    Base(int x) : value{x} {};
    ~Base() {};
};

class Derived: public Base {
    using Base::Base;
    //This allows to automatically inherit non special constructors (non default like default constructor,
    //default copy constr, and default move contrs). This is a feature introduced on C++11.
private:
    int doubled_value;
public:
    //Derived() : doubled_value{0} {};
    Derived() : Base(), doubled_value{0} {};
    //Derived(int x) : doubled_value{x^2} {};
    Derived(int x) : Base(x), doubled_value{x*2} {};
    ~Derived() {};
};

int main()
{
	Base b;
    Derived d {100};
    /* Using the debugger I can see that this way, the d object ends up with value = 0, doubled value = 100. Ofc that's not what we wanted.
    To solver this issue we should apply the commented lines instead of the ones I originally wrote. The notation is the following:
    [derived constructor overload] : [corresponded base constructor overload], [definition] {[behavior]};
    
    This will make the compiler understand that if Im using the overloaded constructor for "int x" on my Derived class, I should use the same 
    overload on my Base class. Before applying that code line, the Base class was using the non-argument constructor. After all this, 
    doubled value would be 100, and value would be 10.
    
    Perhaps we would consider the idea of not defining an overloaded constructor for Derived, since we can use the one on the Base class. Well,
    this wouldn't be correct, as it would leave our doubled value stuffed with trash again.*/
    
	return 0;
}
