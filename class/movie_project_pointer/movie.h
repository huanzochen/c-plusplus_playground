#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie
{
private:
  std::string name;
  std::string rating;
  int watched;

public:
  void set_name(std::string name);
  std::string get_name() const;

  void set_rating(std::string rating);
  std::string get_rating() const;

  void increment_watched();
  int get_watched() const;

  Movie(std::string name, std::string rating, int watched);
  Movie(const Movie &source);
  ~Movie();
};

#endif // MOVIE_H