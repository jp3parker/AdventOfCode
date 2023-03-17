
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

void parseLine(string& line, int& count, int& stack1, int& stack2) {
  string countString;
  int i;
  
  for (i=5; i<line.length(); ++i) {
    if (line[i] == ' ') { ++i; break; }
    countString += line[i];
  }
  count = stoi(countString);
  
  string stack1String;
  for ( i = i + 5; i<line.length(); ++i) {
    if (line[i] == ' ') { ++i; break; }
    stack1String += line[i];
  }
  stack1 = stoi(stack1String) - 1;
  
  string stack2String;
  for ( i=i+3; i < line.length(); ++i) {
    stack2String += line[i];
  }
  stack2 = stoi(stack2String) - 1;
  

}

int main() {
  
  ifstream input;
  input.open("input.txt");
  
  vector< vector<char> > stacks{ { 'R','G','J','B','T','V','Z' },
                                 { 'J','R','V','L' },
                                 { 'S','Q','F' },
                                 { 'Z','H','N','L','F','V','Q','G' },
                                 { 'R','Q','T','J','C','S','M','W' },
                                 { 'S','W','T','C','H','F' },
                                 { 'D','Z','C','V','F','N','J' },
                                 { 'L','G','Z','D','W','R','F','Q' },
                                 { 'J','B','W','V','P' } };
  
  string line;
  for (int i=0; i<10; ++i) {
    getline(input, line, '\n');
  }
  
  while (!input.eof()) {
    getline(input, line, '\n');
    if (line.length() == 0) continue;
    
    int count;
    int stack1;
    int stack2;
    parseLine(line, count, stack1, stack2);
    
    vector<char> subVect;
    for (int i=0; i<count; ++i) {
      subVect.insert(subVect.begin(), stacks[stack1].back());
      stacks[stack1].pop_back();
    }
    for (int i=0; i<count; ++i) {
      stacks[stack2].push_back(subVect[i]);
    }
  }
  
  
  for (int i=0; i<stacks.size(); ++i) {
    cout << stacks[i].back();
  }
  cout << endl;

  return 0;
}
