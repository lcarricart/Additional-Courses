#include <iostream>
#include <string>

using namespace std;

/*We can create constant objects, in order to not allow any modification on it's values:

-------------- 
const Player villain {"Villain", 100, 55};

void display_player_name(const Player &p) {
    cout << p.get_name() << endl;
}

display_player_name(villain); ERROR!
---------------

The compiler is very careful not to allow any changes on the object, so despite the task performed by the method, it won't let it work.
That's when, at the time of defining the prototype for the class, we should add a 'const' at the end of the line,
to tell the compiler that the function is not settled to modify any object.
*/

class Player
{
private:
    string name;
    int health;
    int xp;
public:
    string get_name() const { //This const right here makes all the difference for the program. If we remove it, it doesn't work.
        return name;
    }
    void set_name(string name_val) {
        name = name_val;
    }
    Player();
    Player(string name_val);
    Player(string name_val, int health_val, int xp_val);
};

Player::Player()
    : Player{"None", 0, 0} {
    }
    
Player::Player(string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
    }

void display_player_name(const Player &p) {
    cout << p.get_name() << endl;
}

int main()
{
	const Player villain ("Villain", 100, 55);
    Player hero ("Hero", 100, 15);
    
    cout << villain.get_name() << endl;
    cout << hero.get_name() << endl;
    
	return 0;
}
