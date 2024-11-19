#include <vector>
#include <iostream>
#include <cmath>
#include <cfloat>
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

  double minDiff = DBL_MAX;
  pair<double, double> minDiffCoord;
  for(int i = 0; i < points.size() ;i++){
    double x = points[i].first, y = points[i].second;
    printf("(%f, %f)",x, y);
    if(i != points.size()-1) {
      cout << endl;
    }

    double diff = abs(x - y);
    if(minDiff > diff){
      minDiff = diff;
      minDiffCoord = {x, y};
    }
  }
  cout << endl;

  printf("minDiffCoord = (%f, %f) \n", minDiffCoord.first, minDiffCoord.second);
  return 0;
}