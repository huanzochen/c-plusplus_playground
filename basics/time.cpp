#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
  // get current Time
  time_t currentTime = std::time(nullptr);

  // convert to locale time (GMT +8)
  tm *localTime = localtime(&currentTime);

  // create a stream to hold the formatted time
  stringstream timeStream;

  timeStream << put_time(localTime, "%Y-%m-%d %H:%M:%S");

  string timeString = timeStream.str();

  cout << "Current Time: " << timeString << endl;

  return 0;
}