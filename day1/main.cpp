
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::string;
using std::vector;
using std::sort;

int main() {

  ifstream input;
  input.open("input.txt");
  
  vector<int> allVals;
  
  string line;
  int current_value = 0;
  while (!input.eof()) {
    getline(input, line, '\n');
    if (line.size() > 0) {
      current_value += stoi(line);
    }
    else {
      allVals.push_back(current_value);
      current_value = 0;
    }
  }
  
  sort(allVals.begin(), allVals.end());
  cout << allVals[allVals.size()-1] + allVals[allVals.size()-2] + allVals[allVals.size()-3] << endl;




  return 0;
}
