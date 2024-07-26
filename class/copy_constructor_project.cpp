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

  void display_player(Player p)
  {
    p.set_name("p");
    cout << "Name: " << p.get_name() << endl;
  }

  string get_name()
  {
    return name;
  }

  string greet()
  {
    return "Hello!!";
  }

  Player(string name_val = "None", int health = 0, int xp = 0) : name{name_val}, health{health}, xp{xp}
  {
    cout << "Three args construtors called." << endl;
  }

  // Player(const Player &source) : name{source.name}, health(source.health), xp{source.xp}
  // {
  //   cout << "Copy Constructor - made copy of: " << source.name << endl;
  // }

  // delegating
  Player(const Player &source) : Player{source.name, source.health, source.xp}
  {
    cout << "Copy Constructor - made copy of: " << source.name << endl;
  }

  ~Player()
  {
    cout << "The Player has been destructed." << endl;
  }
};

int main()
{
  Player empty;

  empty.display_player(empty);

  // Player frank{"Frank"};
  // Player hero{"Hero", 100};
  // Player villian{"Villian", 100, 55};

  Player empty2{empty};

  cout << "empty2: " << empty2.greet() << endl;

  return 0;
}