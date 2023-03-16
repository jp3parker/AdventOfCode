
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
  
  int firstStart = 0;
  int firstEnd = 0;
  int secondStart = 0;
  int secondEnd = 0;
  
  string line;
  string num;
  
  while (!input.eof()) {
    getline(input, line, '\n');
    
    if (line.length() == 0) continue;
    
    num = "";
    int i;
    for (i = 0; i < line.length(); ++i) {
      if (line[i] == '-') break;
      num += line[i];
    }
    firstStart = stoi(num);
    
    num = "";
    for (i = i + 1; i < line.length(); ++i) {
      if (line[i] == ',') break;
      num += line[i];
    }
    firstEnd = stoi(num);
    
    num = "";
    for (i = i + 1; i < line.length(); ++i) {
      if (line[i] == '-') break;
      num += line[i];
    }
    secondStart = stoi(num);
    
    num = "";
    for (i = i + 1; i<line.length(); ++i) {
      num += line[i];
    }
    secondEnd = stoi(num);
    
    if (firstStart <= secondEnd and
        firstStart >= secondStart) {
      ++value;
    }
    else if (secondStart <= firstEnd and
             secondStart >= firstStart) {
      ++value;
    }
    
    
  }

  cout << value << endl;

  return 0;
}
