#include <iostream>

using namespace std;

/*Functions or other classes can be 'friends' of a class, which means they have acces to the private data. This privilege must be
granted, NOT taken (with conditions for example); it must be explicitly declared int the class that is granting friendship and done
in the function prototype with the keyword 'friend'.
Friendships are not symmetric, which means that if A is a friend of B, the opposite doesn't apply. Also friendships are not transitive,
so if A is friend of B, and B is friend of C, then the whole chain from A to C doesn't apply.

----------------------------
class Player {
    friend void display_player(Player &p);
    std::string name;
public:
    ...
}
//Declaring display_player in that way saves time not calling a get_name() function, allowing to get it like this 'p.name'.
----------------------------

Methods from other classes can also be declared as friends:
'friend void Other_class::display_player(Player &p);'

Declaring a whole class as a friend:
'friend class Other_class;'

*/

int main()
{
	
    
	return 0;
}
