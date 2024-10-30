#include <iostream>

using namespace std;

int main()
{
	class Deep {
private:
    int *data;
public:
    
    Deep(int d);
    Deep(const Deep &source);
    ~Deep();
};

Deep(int d) {
    data = new int;
    *data = d;
}

Deep(const Deep &source)
//Here the change's done.
{
    data = new int; //New storage allocation.
    *data = *source.data;
    /*If we ever delete a temporal object, here we can see that we separated the adresses of the copied object
    and the original one, so we have two different adresses with the same information.
    Shallow copy: same address, same value.
    Deep copy: different addresses, same value.*/
    cout << "Copy constructor - deep copy" << endl;
}
/*Simplified code would've been:
---------------------------------
Deep(const Deep &source)
    : Deep{*source.data} {
        cout << "Copy constructor - deep" << endl;
      }
---------------------------------
Note that we're delegating constructors.
*/
    
Deep() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_shallow(Deep s) {
    cout << s.get_data_value() << endl;
}

int main()
{
	Deep obj1{100};
    
    display_shallow{obj1};
    
    Deep obj2{obj1};
    
	return 0;
}
