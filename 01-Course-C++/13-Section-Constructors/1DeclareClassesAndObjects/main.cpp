#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
    //attributes
    string name {"Player"}; //I stablish a default value.
    int health {100};
    int xp {3};
    
    //methods
    void talk(string);
    bool is_dead();
};

class Account {
    //attributes
    string name {"Account"};
    double balance {0.0};
    
    //methods
    bool deposit(double);
    bool withdraw(double);
};

int main()
{
	Account frank_account;
    Account jim_account;
    
    Player frank;
    Player hero;
    //This above are two objects.
    
    //Above we show examples of how classes can be used normally as if any other type.
    Player *enemy {nullptr};
    enemy = new Player;
    
    Player players[] {frank};
    vector<Player> player_vec {frank};
    player_vec.push_back(hero);
    
    delete enemy;
    
	return 0;
}
