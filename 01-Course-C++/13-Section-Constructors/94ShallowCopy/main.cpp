#include <iostream>

using namespace std;

class Shallow {
private:
    int *data;
public:
    void set_data_value(int d) {*data = d;}
    int get_data_value() {return *data;}
    
    Shallow(int d);
    Shallow(const Shallow &source); //Copy constructor
    ~Shallow(); //Destructor
};

Shallow::Shallow(int d) {
    data = new int; //Heap
    *data = d;
}

Shallow::Shallow(const Shallow &source)
    : data(source.data) {
        cout << "Copy constructor - shallow copy" << endl;
    }
    
Shallow::~Shallow() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_shallow(Shallow s) /*We're copying the object.*/{
    cout << s.get_data_value() << endl;
}

int main()
{
	Shallow obj1{100};
    //At this moment, value 100 is stored into obj1.
    display_shallow(obj1);
    /*Here we call the function and pass obj1 by value (copy), for which the compiler calls the copy constructor. 's' is created
    and points to the same address as obj1. After that, the object is displayed, and as the function runs out of scope, 's' is 
    destructed. Therefore the information contained in obj1 is erased, but *obj1 still points at the address.*/
    
    Shallow obj2{obj1};
    //The address of obj1 contains garbage data which may cause the compiler to crash.
    
	return 0;
    /*After the main() finishes, the objects run out of scope and the destructors are called, but if the address contains invalid
    data, then it produces a crash.*/
}
