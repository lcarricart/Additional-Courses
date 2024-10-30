#include <iostream>

using namespace std;

//We're gonna analize a better way of initializing values on a constructor.

class Player {
private: 
    string name;
    int health;
    int xp;
public:
    Player()
        : name{"None"}, health{100}, xp{0} {
        }
    /*We preffer this syntax because in the previous initialization way the compiler was defining the
    variables two times. In this new format, the variable is defined only once, being more efficient.
    
    Also notice that the order in which I'm initializing doesn't matter, as the compiler will take the
    declaration as a reference to choose the order of the arguments.*/
    
    Player(string name_val)
        : name{name_val}, health{100}, xp{0} {
        }
    Player(string n, int h, int x)
        : name{n}, health{h}, xp{x} {
        }
};

int main()
{
	Player empty;
    Player frank {"Frank"};
    Player villain {"Villain", 100, 55};
    
	return 0;
}
