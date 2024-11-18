#include <vector>
#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

const double PI = 3.1415926;
const int POINTS = 360;
const double RADIUS = 8000.0;

int main () {
  vector<pair<double, double>> points;

  for(int i = 0; i < POINTS; i++){
    double theta = 2 * PI * i / POINTS;
    double x = RADIUS * cos(theta);
    double y = RADIUS * sin(theta);
    points.push_back({x, y});
  }

  for(int i = 0; i < points.size() ;i++){
    printf("(%f, %f)", points[i].first, points[i].second);
    if(i != points.size()-1) {
      cout << endl;
    }
  }
  cout << endl;

  return 0;
}