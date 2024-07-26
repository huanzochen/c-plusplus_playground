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

  string crying()
  {
    return "嗚嗚！！";
  }

  Player(string name_val = "None", int health = 0, int xp = 0);

  ~Player();
};

// This format is the constructor initialization lists
Player::Player(string name_val, int health, int xp) : name{name_val}, health{health}, xp{xp}
{
  cout << "Three-args constructor called" << endl;
}
Player::~Player()
{
  cout << "Destructor called for " << name << endl;
}

int main()
{

  Player empty;
  Player frank{"Frank"};
  Player hero{"Hero", 10};
  Player villian("Villian", 100, 12);
  villian.set_name("villian");

  // It is able to call directly.
  villian.cry();

  cout << villian.crying() << endl;
}