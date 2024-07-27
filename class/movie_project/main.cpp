#include <iostream>
#include <string>
#include "movies.h"

using namespace std;

int main()
{
  cout << "hello world" << endl;

  Movies controller;
  controller.add_a_movie("MI6", "GTD", 0);       // OK
  controller.add_a_movie("Star Wars", "GTD", 3); // OK
  controller.display_all_movies();

  controller.increment_watched("Star Wars"); // OK
  controller.display_all_movies();

  return 0;
}