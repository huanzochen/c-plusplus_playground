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

  string get_name_not_const()
  {
    return this->name;
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

// void display_player_name(const Player &player)
// {
//   // Can not guarantee get_name_not_const is const function.
//   cout << player.get_name_not_const() << endl;
// }

int main()
{
  const Player john{"john", 100, 10};

  // This line will get error because john is const.
  // john.set_name("johnathan");

  cout << "johns name is: " << john.get_name() << endl;
  john.print_name();

  // Becuase hero is not a const, the compiler didn't care about the value of it.
  Player hero{"heroJames", 1000, 100};
  hero.set_name("heroJAMES!!");
  cout << "hero name is: " << hero.get_name() << endl;
  hero.print_name();

  // These two lines will cause error cause the get_name_not_const() is not const function.
  // display_player_name(john);
  // display_player_name(hero);
}