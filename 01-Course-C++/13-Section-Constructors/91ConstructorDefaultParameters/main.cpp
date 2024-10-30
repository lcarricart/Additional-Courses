#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    string name;
    int health;
    int xp;
public:
    Player(string name_val = "None", int health_val = 0, int xp_val = 0);
};
    /*So we have this first declaration where we set the default values, and
    below we have the default definition (for delegating the constructor). It's
    written this way 'cause its only purpose is to set default values.
    
    One advantage of setting default values is that now I can create an object
    passing only two parameters, which would have been a compiling error in prior
    examples (because there was no case for two parameters in the overload).*/
    
Player::Player(string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
}

/*This program shows that I can avoid overloading the constructor a thousand times for
each case stablishing a constructor with default parameters. This does the same as the
example on 7.DefaultConstructor where I defined three overloadings, but in this case only
defining one.*/
  
int main()
{
	Player empty;
    Player frank {"Frank"};
    Player hero {"Hero", 100};
    Player villain {"Villain", 100, 55};
    
	return 0;
}
