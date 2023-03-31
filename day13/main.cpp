#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
using namespace std;

struct element {
  bool list;
  int val;
  vector<element*> items;
};

void parse(element* packet, string& line, int index) {
  if (line[index] == '[') {
    packet->list = true;
    parse
  }
  else if () {
  
  }
}

int main() {
  
  ifstream input;
  input.open("input.txt");
  
  vector<element*> packets;
  
  string line;
  getline(input, line, '\n');
  while (line.length() > 0) {
    element* packet;
    parse(packet, line, 0);
    packets.push_back(packet);
    getline(input, line, '\n');
  }
  
  

  return 0;
}
