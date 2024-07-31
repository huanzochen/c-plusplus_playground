#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

using namespace std;

class Player
{
private:
  static int num_players;
  string name;
  int health;
  int xp;

public:
  static int get_active_players();

  // Constructor
  Player(string name, int health, int xp);

  // Copy constructor
  Player(const Player &source);

  // Destructor
  ~Player();
};

#endif // _PLAYER_H_