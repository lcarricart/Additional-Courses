#include <iostream>
#include <string>

using namespace std;

class Player {
public:
    //attributes
    string name {"Player"}; //I stablish a default value.
    int health {100};
    int xp {3};
    
    //methods
    void talk(string text_to_say) {cout << name << ": -" << text_to_say << endl;};
    bool is_dead();
};

class Account {
public:
    //attributes
    string name {"Account"};
    double balance {0.0};
    
    //methods
    void deposit(double bal) {balance += bal; cout << "In deposit" << endl;};
    void withdraw(double wit) {balance-= wit; cout << "In withdraw" << endl;};
};


int main()
{
	Account frank_account;
    frank_account.name = "Frank's account";
    frank_account.balance = 5000.0;
    
    frank_account.deposit(1000.0);
    frank_account.withdraw(500);
    
    Player frank;
    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;
    frank.talk("Hi there");
    
    Player *enemy = new Player;
    enemy->name = "Enemy";
    (*enemy).health = 100;
    enemy->xp = 15;
    enemy->talk("I will destroy you");
    
	return 0;
}
