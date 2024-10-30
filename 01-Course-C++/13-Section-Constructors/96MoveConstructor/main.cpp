#include <iostream>
#include <vector>

using namespace std;

/*Move constructors are not a begginer level concept; they were implemented in C++11. The purpose is to not call copy constructor
multiple times occupying tons of space. The move constructor just moves the object from one place to another.*/

class Move {
private:
    int *data;
public:
    
    Move(int d); //Constructor
    Move(const Move &source); //Copy constructor (to test program).
    Move (Move &&source) noexcept; //Move constructor. No 'const' because we wanna modify the value.
    ~Move(); //Destructor
};

Move::Move(int d) {
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

//Copy constructor
Move::Move(const Move &source)
    : Move(*source.data) {
        cout << "Copy constructor - deep copy for: " << *data << endl;
    }

//Move constructor
Move::Move(Move &&source) noexcept
    : data{source.data} {
        source.data = nullptr;
        cout << "Move constructor - moving resource: " << *data << endl;
    }
/*To see the effects of the 'Move constructor', comment all this function. Let's call 'Case 1' to the one without 'move constructor' and
'Case 2' to the one including it.
On Case 1 the copy constructor is called every time the push_back is called for the vector, as expected. But what is not so intuitive,
is that each time we ask the vector to dynamically increase it's size, more object constructions are called behind the scenes to finish
the task. In our minds, the copy constructor might have to be called only 8 times, but in reality is being called 15.
On Case 2 we get more efficience due to the move constructor, which only moves objects instead of constantly creating and destructing
them. The 'move constructor' is automatically called instead of the 'copy' because of it's '&&'. The compiler identifies that the data
matches better with the && rather than with & (kind of an overload, if not).*/

//Destructor
Move::~Move() {
    if (data != nullptr) {
        cout << "Destructor freeing data for: " << *data << endl;
    } else {
        cout << "Destructor freeing data for nullprt" << endl;
    }
    delete data;
}

int main()
{
	vector<Move> vec;
    
    //In this case, a vector of objects is created. This object has only one parameter, so it can be seen as a simple variable instead of object.
    vec.push_back(Move(10));
    
    vec.push_back(Move(20));
    vec.push_back(Move(30));
    vec.push_back(Move(40));
    vec.push_back(Move(50));
    vec.push_back(Move(60));
    vec.push_back(Move(70));
    vec.push_back(Move(80));
    
	return 0;
}
