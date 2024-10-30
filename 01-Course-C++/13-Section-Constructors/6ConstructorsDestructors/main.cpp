#include <iostream>
#include <string>

using namespace std;

class Player
{
private: 
    string name;
    int health;
    int xp;
public: 
    void set_name(string name_val) {name = name_val; }
    
    //A constructor is the one in charge of creating objects. Priorly we didn't define it but it was done automatically.
    //Overloaded constructor (means it has many definitions depending on the arguments).
    Player() {
        cout << "No arguments constructor called" << endl;
    }
    Player(string name) {
        cout << "String argument constructor called" << endl;
    }
    Player(string name, int health, int xp) {
        cout << "Three arguments constructor called" << endl;
    }
    ~Player() { //A destructor is called with this '~' at the beggining.
        cout << "Destructor called for " << name << endl;
    }
 };

int main()
{
	{
        Player slayer;
        slayer.set_name("Slayer");
    }
    /*The sense of that {} is that when a class gets out of scope, 
    it's automatically destructed by the compiler, so we don't have to do it.*/
    
    {
        Player frank;
        frank.set_name("Frank");
        Player hero("Hero");
        hero.set_name("Hero");
        Player villain("Villain", 100, 12);
        villain.set_name("Villain");
    }
    /*It's interesting to analyze that the compiler destructs first the last object created (villain in this case),
    followed by 'Hero' and ending with 'Frank'.*/
    
    Player *enemy = new Player;
    enemy->set_name("Enemy");
    //The same as above but using a pointer instead of a reference name.
    
    Player *level_boss = new Player("Level Boss", 1000, 300);
    level_boss->set_name("Level Boss");
    
    delete enemy;
    delete level_boss;
    
	return 0;
}
