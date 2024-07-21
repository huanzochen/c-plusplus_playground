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
  Player() : name{0}, health{0}, xp{0}
  {
    cout << "No args constructor called" << endl;
  }
  Player(string name_val) : name{name_val}, health{0}, xp{0}
  {
    cout << "String arg construtor called" << endl;
  }
  // Player(string name)
  // {
  //   this->name = name;
  //   cout << "String arg construtor called" << endl;
  // }
  Player(string name_val, int health, int xp) : name{name_val}, health{health}, xp{xp}
  {
    cout << "3 args constructor called" << endl;
  }
  ~Player()
  {
    cout << "Destructor called for " << name << endl;

    // maybe execute delete xxx if there is pointer has been newed.
  }
};

int main()
{
  {
    Player tommy;
    tommy.set_name("tommy");
  }

  {
    Player frank;
    frank.set_name("Frank");
    Player hero;
    hero.set_name("hero");
    Player villian("Villian", 100, 12);
    villian.set_name("villian");
  }

  Player *enemy{new Player("enemy", 1000, 10)};
  enemy->yell();

  delete enemy;

  Player *vivian{new Player("vivian", 10, 10)};
  vivian->cry();

  delete vivian;
}