#include "movie.h"
#include <iostream>
#include <string>

// Constructor of Movie
Movie::Movie(std::string name, std::string rating, int watched)
{
  this->name = name;
  this->rating = rating;
  this->watched = watched;
  std::cout << "Constructing a new movie method. " << "name: " << name << " rating: " << rating << " watched: " << watched << std::endl;
}

// Copy constructor
Movie::Movie(const Movie &source) : name{source.name}, rating{source.rating}, watched{source.watched}
{
  std::cout << "Copying movie: " << source.name << std::endl;
};

// Deconstructor
Movie::~Movie()
{
  std::cout << "Deconstruct of movie" << std::endl;
}

void Movie::set_name(std::string name)
{
  this->name = name;
}
std::string Movie::get_name() const { return this->name; }

void Movie::set_rating(std::string rating)
{
  this->rating = rating;
}
std::string Movie::get_rating() const { return this->rating; }

void Movie::increment_watched()
{
  watched++;
}
int Movie::get_watched() const
{
  return this->watched;
}