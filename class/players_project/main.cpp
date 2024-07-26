#include <iostream>
#include "player.h"

using namespace std;

void display_active_players()
{
  cout << "Active players: " << Player::get_active_players() << endl;
}

int main()
{
  display_active_players();

  Player tommy{"Tommy", 1000, 10};

  {
    Player frank{"frank", 10, 10};
    display_active_players();
  }

  Player *enemy = new Player("Enemy", 100, 100);

  display_active_players();
  delete enemy;

  display_active_players();

  return 0;
}