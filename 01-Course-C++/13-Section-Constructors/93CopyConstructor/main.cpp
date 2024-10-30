#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    string name;
    int health;
    int xp;
public:
    string get_name() {return name; }
    int get_health() {return health; }
    int get_xp() {return xp; }
    
    Player(string name_val = "None", int health_val = 0, int xp_val = 0);
    
    //Copy constructor. We use it const to not be able to touch the original object.
    Player (const Player &source);
    //Destructor
    ~Player() {cout << "Destructor called for: " << name << endl;}
};

Player::Player(string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
        cout << "Three argument constructor for " + name << endl;
    }
    
Player::Player(const Player &source)
    : name{source.name}, health{source.health}, xp{source.xp}
    /*We could also delegate here: 'Player {source.name, source.health, source.xp} {
        }'*/
    {
        cout << "Copy constructor - made copy of " << source.name << endl;
    }
/*This is the copy constructor, and serves to make a copy of an object, like in: 'Player my_new_object {empty};'.
Solves the case in which we have an object as a parameter. Both pointers of the objects will be pointing at same address.
That causes an issue for when we destruct one object, as the other one keeeps pointing at a location where there's no information.
Those are the cases when we use deep copies, subject analized in the next file.*/

void display_player(Player p) {
//That 'p' is the copy of an object. This is only possible because we defined our copy constructor, which is called automatically.
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "Xp: " << p.get_xp() << endl;
}

/*Copy constructors are used usually for passing an object as a parameter into a function, or for function's return values.
We should be totally focused on object passing when working with raw pointer.

This is an easy example on how to copy an object:
    Player hero {"Hero", 100, 100};
    Player another_hero {hero};*/

int main()
{
	Player empty;
    
    Player my_new_object {empty}; //Here my copy constructor will be called.
    
    display_player(empty);
    
	return 0;
}
