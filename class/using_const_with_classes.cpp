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
  void set_name(string name)
  {
    (*this).name = name;
  }

  string get_name() const
  {
    return (*this).name;
  }

  void print_name() const;

  // Constructor
  Player(string name, int health, int xp) : name{name}, health{health}, xp{xp}
  {
    cout << "Constructor initailized the values." << endl;
  }

  // Deconstructor
  ~Player()
  {
  }
};

// Both assign const declaration in the class function prototype and class function definition.
// You ensure that the method does not modify any member variables of the Player instance.
void Player::print_name() const
{
  cout << "the player name is: " << name << endl;
}

int main()
{
  const Player john{"john", 100, 10};

  // This line will get error because john is const.
  // john.set_name("johnathan");

  cout << "johns name is: " << john.get_name() << endl;
  john.print_name();
}