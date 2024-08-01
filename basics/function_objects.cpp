#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Square_Functor
{
  void operator()(int x)
  {
    cout << x * x << " ";
  }
};

template <typename T>
struct Displayer
{
  void operator()(const T &data)
  {
    cout << data << " ";
  }
};

class Multipler
{
private:
  int num{};

public:
  Multipler(int n) : num{n} {}
  void operator()(int n) const
  {
    cout << n * num << " ";
  }
};

int main()
{
  cout << "\nTest1 ===============================" << endl;
  Square_Functor square;
  square(4); // square.operator()(4) will output 16;

  Displayer<int> dInt;
  Displayer<string> dString;

  dInt(2);
  dString("This is a string from Displayer.");

  cout << "\nTest2 ===============================" << endl;

  vector<int> vec{1, 2, 3, 4, 5};
  std::for_each(vec.begin(), vec.end(), square);
  std::for_each(vec.begin(), vec.end(), Displayer<int>());
  std::for_each(vec.begin(), vec.end(), dInt);
  cout << endl;

  vector<string> vecName{"Tommy", "Kevin", "Rita", "Andy"};
  std::for_each(vecName.begin(), vecName.end(), dString);
  std::for_each(vecName.begin(), vecName.end(), Displayer<std::string>());

  cout << "\nTest3 ==========================" << endl;
  std::for_each(vec.begin(), vec.end(), [](int x)
                { cout << x * x << " "; });
  std::for_each(vecName.begin(), vecName.end(), [](string s)
                { cout << s << " "; });

  cout << "\nTest4 ============================" << endl;
  Multipler a(2);
  // 2*3 = 6;
  a(3);

  cout << "\nTest5 =====================================" << endl;
  Multipler mulHundred{100};
  vector vecHundred{1, 2, 3, 4};
  Displayer<int> dMulti;

  std::for_each(vecHundred.begin(), vecHundred.end(), mulHundred);
  for_each(vecHundred.begin(), vecHundred.end(), dMulti);

  std::transform(vecHundred.begin(), vecHundred.end(), vecHundred.begin(), [](int i)
                 { return i * 100; });
  std::for_each(vecHundred.begin(), vecHundred.end(), Displayer<int>());

  return 0;
}