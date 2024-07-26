#include <iostream>
#include "player.h"

int Player::num_players{0};

int Player::get_active_players()
{
  return num_players;
}

// Constructor, ++value of players.
Player::Player(string name, int health, int xp)
{
  std::cout << "constructor, and will add num_players 1" << std::endl;
  ++num_players;
}

// Copy constructor
// Because it is using delegating from Constructor, no need to ++num_players.
Player::Player(const Player &source) : Player{source.name, source.health, source.xp}
{
  std::cout << "copy constructor!!" << std::endl;
}

// Destructor, --value of players.
Player::~Player()
{
  --num_players;
}