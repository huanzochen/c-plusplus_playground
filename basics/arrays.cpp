#include <iostream>

using namespace std;

int main()
{
  int test_scores[5];

  cout << "\n test_scores:" << test_scores << endl;

  int test_scores_num[5] = {100, 95, 99, 87, 88};

  // this is wrong, because sizeof is not the length of an array.
  // As you can see not bound check is performed here.
  for (int i = 0; i < sizeof(test_scores_num); i++)
  {
    cout << "scores of test:" << test_scores_num[i] << endl;
  }

  char vowels[] = {
      'a', 'e', 'i',
      'o', 'u'};
  cout << "\n the first vowel is:" << vowels[0] << endl;

  cout << "\n the last vowel is:" << vowels[4] << endl;

  int movie_rating[3][4] = {{0, 4, 3, 5},
                            {2, 3, 3, 5},
                            {1, 4, 4, 5}};

  cout << "00:" << movie_rating[0][0] << endl;
  cout << "01:" << movie_rating[0][1] << endl;
}