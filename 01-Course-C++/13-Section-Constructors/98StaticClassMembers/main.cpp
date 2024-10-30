#include <iostream>
#include "player.h"

using namespace std;

/*This concept is about static variables inside a class. This could be useful understanding the following case: imagine you need to count
the ammount of players (or objects) existing on your class at a certain moment, then you would need to count them each time you
construct an object, and dismiss them each time you destruct them. Instead of updating the number every time and making the code so 
complicated, we create an static class variable.*/

void display_active_players() {
    cout << "Active players: " << Player::get_num_players() << endl;
}

int main()
{
	display_active_players();
    Player hero("Hero");
    display_active_players();
    
    {
        //Local block
        Player frank("Frank");
        display_active_players();
    }
    
    display_active_players();
    
	return 0;
}
