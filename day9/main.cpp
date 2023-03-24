#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::string;
using std::vector;
using std::sort;
using std::unordered_map;
using std::map;
using std::pair;
using std::make_pair;
using std::sqrt;


int main() {
  
  ifstream input;
  input.open("input.txt");
  
  map<pair<int,int>, bool> tracker;
  tracker[ make_pair(0, 0) ] = true;
  
  vector< pair<int,int> > knots;
  for (int i=0; i<10; ++i) {
    knots.push_back( make_pair(0,0) );
  }
  
  int counter = 1;
  double sqr2 = 1.42;
  
  string line;
  getline(input, line, '\n');
  while (line.length() > 0) {
    char D = line[0];
    int count = stoi(line.substr(2, line.length() - 2));

    for (int i=0; i<count; ++i) {
      if (D == 'U') {
        ++knots[0].second;
      }
      else if (D == 'R') {
        ++knots[0].first;
      }
      else if (D == 'D') {
        --knots[0].second;
      }
      else { // 'L'
        --knots[0].first;
      }
      for (int j=1; j<10; ++j) {
        int xsqr = (knots[j-1].first - knots[j].first) * (knots[j-1].first - knots[j].first);
        int ysqr = (knots[j-1].second - knots[j].second) * (knots[j-1].second - knots[j].second);
        if (sqrt(xsqr + ysqr) > sqr2) {
          if (knots[j-1].first > knots[j].first) {
            ++knots[j].first;
          }
          else if (knots[j-1].first < knots[j].first) {
            --knots[j].first;
          }
          if (knots[j-1].second > knots[j].second) {
            ++knots[j].second;
          }
          else if (knots[j-1].second < knots[j].second) {
            --knots[j].second;
          }
        }
      }
      if (tracker[ knots[9] ] == false) {
        tracker[ knots[9] ] = true;
        ++counter;
      }
    }
    getline(input, line, '\n');
  }
  
  cout << counter << endl;

  
  

  return 0;
}
