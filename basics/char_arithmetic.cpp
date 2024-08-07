#include <iostream>
#include <string>
#include <array>

using namespace std;

int main()
{
  // char test[26];
  char test[26] = {0}; // Initialize all elements to '\0'

  test['c' - 'a'] = 'c';
  test['b' - 'a'] = 'b';
  test['a' - 'a'] = 'a'; // This should be at test[0]

  cout << "test[i]: ";
  for (int i = 0; i < 26; i++)
  {
    cout << test[i];
    if (i != 25)
      cout << ", ";
  }
  cout << endl;

  std::array<char, 26> test2;
  test2.fill('\0');

  test2['c' - 'a'] = 'c';
  test2['b' - 'a'] = 'b';
  test2['a' - 'a'] = 'a';

  test2['g' - 'a'] = 'g';
  test2['e' - 'a'] = 'e';

  cout << "test2[i]: ";
  for (int i = 0; i < test2.size(); i++)
  {
    cout << test2[i];
    if (i != test2.size() - 1)
      cout << ", ";
  }
  cout << endl;


  // 用相對位置來算空間, 這樣是 2
  cout << "'c' - 'a': " << 'c' - 'a' << endl;
}