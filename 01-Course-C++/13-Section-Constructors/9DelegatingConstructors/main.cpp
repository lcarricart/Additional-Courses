#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    string name;
    int health;
    int xp;
public:
    Player(string name_val, int health_val, int xp_val)
        : name{name_val}, health{health_val}, xp{xp_val} {
        }
    /*Now that we have this initialization reference, we can use that code into another constructor case.
    This delegating only works using the 'initialization list' syntax.*/
    
    Player(string name_val)
        : Player {name_val, 0, 0} {
        }
    //I'm delegating the constructor (using the first one and just introducing my new values).
    
    Player()
        : Player {"None", 0, 0} {
            cout << "No argument constructor.";
        }
};

int main()
{
	
    
	return 0;
}
