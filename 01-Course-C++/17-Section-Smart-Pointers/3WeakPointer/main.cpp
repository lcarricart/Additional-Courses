#include <iostream>
#include <memory>

using namespace std;

class B; //This works as a class declaration. While working with my class A, the compiler doesn't understand that I will declare class B later.

class A {
    shared_ptr<B> b_ptr; //Part of its definition comes from B.
public:
    void set_B(shared_ptr<B> &b) {b_ptr = b;};
    A() {cout << "A Constructor" << endl;};
    ~A() {cout << "A Destructor" << endl;};
};

class B {
    shared_ptr<A> a_ptr; //Part of its definition comes from A.
public:
    void set_A(shared_ptr<A> &a) {a_ptr = a;};
    B() {cout << "B Constructor" << endl;};
    ~B() {cout << "B Destructor" << endl;};
};


int main()
{
	shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->set_B(b);
    b->set_A(a);
    
	return 0;
}
