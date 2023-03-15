
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::string;
using std::vector;
using std::sort;
using std::unordered_map;


void fillMap(unordered_map<char, bool>& map, string& line) {
  for (int i=0; i<line.length(); ++i) {
    map[line[i]] = true;
  }
}

int main() {
  
  ifstream input;
  input.open("input.txt");
  
  int value = 0;
  string line;
  while (!input.eof()) {
    unordered_map<char, bool> first;
    unordered_map<char, bool> second;
  
    getline(input, line, '\n');
    fillMap(first, line);
    getline(input, line, '\n');
    fillMap(second, line);
    getline(input, line, '\n');
    
    for (int i=0; i<line.length(); ++i) {
      if (first[line[i]] == true and second[line[i]] == true) {
        if (line[i] < 'a') { // capital
          value += (line[i] - 'A' + 27);
        }
        else { // lowercase
          value += (line[i] - 'a' + 1);
        }
        break;
      }
    }
    
  }

  cout << value << endl;

  return 0;
}
