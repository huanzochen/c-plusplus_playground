#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <vector>
#include "movie.h"

// main should only interact with Movies class
class Movies
{
public:
  bool add_a_movie(std::string name, std::string rating, int watched);

  bool increment_watched(std::string name);

  void display_all_movies() const;

  // Constructor
  Movies();

  // DeConstructor
  ~Movies();

private:
  std::vector<Movie> *collections;
};

#endif // MOVIES_H