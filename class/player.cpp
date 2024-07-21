#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
  // attributes
  // string name;
  // int health;
  // int xp;

  // C++11 features allowing to do this
  string name{"Player"};
  int health{3};
  int xp{100};

  // methods
  void talk(string text_to_say);
  bool isdead();
};

class Account
{
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

  Player players[]{frank, hero};

  vector<Player> player_vec{frank};
  player_vec.push_back(hero);

  Player *enemy{nullptr};
  enemy = new Player;

  delete enemy;

  cout << "hello world!" << endl;

  return 0;
}