#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
public:
  // attributes
  // string name;
  // int health;
  // int xp;

  // C++11 features allowing to do this
  string name{"Player"};
  int health{3};
  int xp{100};

  // methods
  void talk(string textToSay) { cout << name << " says: " << textToSay << endl; }
  bool isdead();
};

class Account
{
public:
  // attributes
  // string name;
  // double balance;

  // C++11 features allowing to initilize the Account variables default value on class declaration.
  string name{"Account"};
  double balance{0.0};

  // methods
  bool withdraw(double amount);
  bool deposit(double amount);
};

int main()
{
  Player frank;
  Player hero;

  frank.name = "Frank";
  frank.health = 110;
  frank.xp = 1500;

  frank.talk("Hello, I'm Frank!");

  cout << frank.name << endl;
  cout << "frank.health: " << frank.health << endl;

  Player players[]{frank, hero};

  vector<Player> player_vec{frank};
  player_vec.push_back(hero);

  Player *enemy{nullptr};
  enemy = new Player;

  delete enemy;

  Player *tommy{new Player};
  tommy->name = "Tommy";
  tommy->health = 999;
  tommy->xp = 1000;

  tommy->talk("Hi there");

  cout << "Tommy.health:" << tommy->health << endl;

  cout << "hello world!" << endl;

  return 0;
}