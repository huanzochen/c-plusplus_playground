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
  void set_name(string name_val)
  {
    name = name_val;
  }

  void yell()
  {
    cout << "HAHAHA!!" << endl;
  }

  void cry()
  {
    cout << "嗚嗚!!" << endl;
  }

  // Overload Constructors

  // This formay is the constructor initialization lists
  Player() : Player{"name", 0, 0}
  {
    cout << "no args constructor" << endl;
  }
  Player(string name_val) : Player{name_val, 0, 0}
  {
    cout << "One arg construtor called" << endl;
  }
  // Player(string name)
  // {
  //   this->name = name;
  //   cout << "String arg construtor called" << endl;
  // }
  Player(string name_val, int health, int xp) : name{name_val}, health{health}, xp{xp}
  {
    cout << "Three-args constructor called" << endl;
  }
  ~Player()
  {
    cout << "Destructor called for " << name << endl;

    // maybe execute delete xxx if there is pointer has been newed.
  }
};

int main()
{

  Player empty;
  Player frank;
  frank.set_name("Frank");
  Player hero;
  hero.set_name("hero");
  Player villian("Villian", 100, 12);
  villian.set_name("villian");
}