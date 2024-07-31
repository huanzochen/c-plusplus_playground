#include <iostream>
#include <string>
#include <vector>
#include "movie.h"
#include "movies.h"

Movies::Movies()
{
}

Movies::~Movies()
{
  std::cout << "Deconstruct of movies" << std::endl;
}

bool Movies::add_a_movie(std::string name, std::string rating, int watched)
{
  for (const Movie &movie : collections)
  {
    if (movie.get_name() == name)
    {
      std::cout << "The movie: " << name << " is already exists!" << std::endl;
      return false;
    }
  }

  // Add the movie name to the collections
  Movie temp{name, rating, watched};
  collections.push_back(temp);
  std::cout << "Added movie: " << name << std::endl;

  return true;
}

bool Movies::increment_watched(std::string name)
{
  for (Movie &movie : collections)
  {
    if (movie.get_name() == name)
    {
      movie.increment_watched();
      return true;
    }
  }

  std::cout << "No movie <<" << name << ">> here." << std::endl;
  return false;
}

void Movies::display_all_movies() const
{
  if (collections.size() == 0)
  {
    std::cout << "There is no any movie here." << std::endl;
  }
  else
  {
    std::cout << "Movies: " << std::endl;
    // for (const Movie &movie : collections)
    // for (auto movie : collections)
    for (const auto &movie : collections)
    {
      std::cout << "Movie: " << movie.get_name() << ", Watched: " << movie.get_watched() << " times." << std::endl;
    }
  }
}