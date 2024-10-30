#include <iostream>
#include "player.h"

/*We wanna initialize the static variables num_players here.
We can't do it inside the 'class' in the h. file.*/
int Player::num_players{0};

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
        ++num_players;
        //We increment it in every overloaded constructor we might have. Not in the Copy constructor because it delegates heres.
    }

Player::Player(const Player &source)
    : Player(source.name, source.health, source.xp) {
    }
    
Player::~Player() {
    --num_players;
}

int Player::get_num_players() {
    return num_players;
}