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
  
  vector<int> indexes{ 20, 60, 100, 140, 180, 220 };
  
  vector<int> x;
  x.push_back(1);
  
  string line;
  getline(input, line, '\n');
  while (line.length() > 0) {
    if (line.compare("noop") == 0) {
      x.push_back(x[x.size()-1]);
    }
    else {
      int val = stoi(line.substr(5, line.length() - 5));
      x.push_back(x[x.size()-1]);
      x.push_back(x[x.size()-1] + val);
    }
    getline(input, line, '\n');
  }
  
  
  for (int i=0; i<240; ++i) {
    if (x[i] - 1 == i % 40 || x[i] == i % 40 || x[i] + 1 == i % 40) {
      cout << "#";
    }
    else {
      cout << ".";
    }
    if (i % 40 == 39) cout << endl;
  }
  
  

  return 0;
}
