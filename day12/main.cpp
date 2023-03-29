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
using std::find;

struct square {
  char height;
  vector<square*> conns;
  double path; // starts at inf
  double weight;
  int val;
};

void astar(square* start);

int main() {
  
  ifstream input;
  input.open("input.txt");
  vector< vector<square*> > land;
  
  square* start;
  
  string line;
  getline(input, line, '\n');
  while (line.length() > 0) {
    vector<square*> row;
    for (int i=0; i<line.length(); ++i) {
      square* s = new square;
      if (line[i] == 'S') {
        s->height = 'a';
      }
      else if (line[i] == 'E') {
        start = s;
        s->height = 'z';
      }
      else {
        s->height = line[i];
      }
      row.push_back(s);
    }
    land.push_back(row);
    getline(input, line, '\n');
  }
  
  for (int i=0; i<land.size(); ++i) {
    for (int j=0; j<land[i].size(); ++j) {
      land[i][j]->val = INT_MAX;
      if (i > 0 and land[i][j]->height + 1 >= land[i - 1][j]->height) { // look up
        land[i - 1][j]->conns.push_back(land[i][j]);
      }
      if (j < land[i].size() - 1 and land[i][j]->height + 1 >= land[i][j + 1]->height) { // look right
        land[i][j + 1]->conns.push_back(land[i][j]);
      }
      if (j > 0 and land[i][j]->height + 1 >= land[i][j - 1]->height) { // look left
        land[i][j - 1]->conns.push_back(land[i][j]);
      }
      if (i < land.size() - 1 and land[i][j]->height + 1 >= land[i + 1][j]->height) { // look down
        land[i + 1][j]->conns.push_back(land[i][j]);
      }
    }
  }
  
  start->path = 0;
  start->weight = 0;
  start->val = 0;
  astar(start);
  
  int smallest = INT_MAX;
  for (int i=0; i<land.size(); ++i) {
    for (int j=0; j<land[i].size(); ++j) {
      if (land[i][j]->height == 'a' and land[i][j]->val < smallest) {
        smallest = land[i][j]->val;
      }
    }
  }
  cout << smallest << endl;

  return 0;
}

void astar(square* start) {
  for (int i=0; i<start->conns.size(); ++i) {
    if (start->val + 1 < start->conns[i]->val) {
      start->conns[i]->val = start->val + 1;
      astar(start->conns[i]);
    }
  }
}
