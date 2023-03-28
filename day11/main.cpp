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

struct item {
  vector<int> mods;
};

struct monkey {
  vector<item*> items;
  int d;
  int t;
  int f;
  int count;
};

vector<int> getItems(string line) {
  int index = 18;
  vector<int> items;
  while (index < line.length()) {
    items.push_back(stoi(line.substr(index, 2)));
    index += 4;
  }
  return items;
}

int main() {
  ifstream input;
  input.open("input.txt");
  
  vector<monkey*> monkeys;
  
  string line;
  getline(input, line, '\n');
  for (int i=0; i<8; ++i) {
    getline(input, line, '\n');
    
    vector<int> items = getItems(line);
    
    getline(input, line, '\n');
    getline(input, line, '\n');
    
    int d = stoi(line.substr(21, line.length() - 21));
    
    getline(input, line, '\n');
    
    int t = stoi(line.substr(29, line.length() - 29));
    
    getline(input, line, '\n');
    
    int f = stoi(line.substr(30, line.length() - 30));
    
    getline(input, line, '\n');
    getline(input, line, '\n');
    
    monkey* monk = new monkey;
    for (int j=0; j<items.size(); ++j) {
      item* newItem = new item;
      newItem->mods.push_back(items[j] % 5);
      newItem->mods.push_back(items[j] % 17);
      newItem->mods.push_back(items[j] % 7);
      newItem->mods.push_back(items[j] % 13);
      newItem->mods.push_back(items[j] % 19);
      newItem->mods.push_back(items[j] % 3);
      newItem->mods.push_back(items[j] % 11);
      newItem->mods.push_back(items[j] % 2);
      monk->items.push_back(newItem);
    }
    monk->d = d;
    monk->t = t;
    monk->f = f;
    monk->count = 0;
    monkeys.push_back(monk);
  }
  
  for (int i=0; i<10000; ++i) {

    while (monkeys[0]->items.size()) {
      ++monkeys[0]->count;
      monkeys[0]->items[0]->mods[0] = monkeys[0]->items[0]->mods[0] * 7 % 5;
      monkeys[0]->items[0]->mods[1] = monkeys[0]->items[0]->mods[1] * 7 % 17;
      monkeys[0]->items[0]->mods[2] = monkeys[0]->items[0]->mods[2] * 7 % 7;
      monkeys[0]->items[0]->mods[3] = monkeys[0]->items[0]->mods[3] * 7 % 13;
      monkeys[0]->items[0]->mods[4] = monkeys[0]->items[0]->mods[4] * 7 % 19;
      monkeys[0]->items[0]->mods[5] = monkeys[0]->items[0]->mods[5] * 7 % 3;
      monkeys[0]->items[0]->mods[6] = monkeys[0]->items[0]->mods[6] * 7 % 11;
      monkeys[0]->items[0]->mods[7] = monkeys[0]->items[0]->mods[7] * 7 % 2;
      if (monkeys[0]->items[0]->mods[0] == 0) {
        monkeys[monkeys[0]->t]->items.push_back(monkeys[0]->items[0]);
      }
      else {
        monkeys[monkeys[0]->f]->items.push_back(monkeys[0]->items[0]);
      }
      monkeys[0]->items.erase(monkeys[0]->items.begin(), monkeys[0]->items.begin()+1);
    }
    
    while (monkeys[1]->items.size()) {
      ++monkeys[1]->count;
      monkeys[1]->items[0]->mods[0] = monkeys[1]->items[0]->mods[0] * monkeys[1]->items[0]->mods[0] % 5;
      monkeys[1]->items[0]->mods[1] = monkeys[1]->items[0]->mods[1] * monkeys[1]->items[0]->mods[1] % 17;
      monkeys[1]->items[0]->mods[2] = monkeys[1]->items[0]->mods[2] * monkeys[1]->items[0]->mods[2] % 7;
      monkeys[1]->items[0]->mods[3] = monkeys[1]->items[0]->mods[3] * monkeys[1]->items[0]->mods[3] % 13;
      monkeys[1]->items[0]->mods[4] = monkeys[1]->items[0]->mods[4] * monkeys[1]->items[0]->mods[4] % 19;
      monkeys[1]->items[0]->mods[5] = monkeys[1]->items[0]->mods[5] * monkeys[1]->items[0]->mods[5] % 3;
      monkeys[1]->items[0]->mods[6] = monkeys[1]->items[0]->mods[6] * monkeys[1]->items[0]->mods[6] % 11;
      monkeys[1]->items[0]->mods[7] = monkeys[1]->items[0]->mods[7] * monkeys[1]->items[0]->mods[7] % 2;
      if (monkeys[1]->items[0]->mods[1] == 0) {
        monkeys[monkeys[1]->t]->items.push_back(monkeys[1]->items[0]);
      }
      else {
        monkeys[monkeys[1]->f]->items.push_back(monkeys[1]->items[0]);
      }
      monkeys[1]->items.erase(monkeys[1]->items.begin(), monkeys[1]->items.begin()+1);
    }
    
    while (monkeys[2]->items.size()) {
      ++monkeys[2]->count;
      monkeys[2]->items[0]->mods[0] = monkeys[2]->items[0]->mods[0] + 8;
      monkeys[2]->items[0]->mods[1] = monkeys[2]->items[0]->mods[1] + 8;
      monkeys[2]->items[0]->mods[2] = monkeys[2]->items[0]->mods[2] + 8;
      monkeys[2]->items[0]->mods[3] = monkeys[2]->items[0]->mods[3] + 8;
      monkeys[2]->items[0]->mods[4] = monkeys[2]->items[0]->mods[4] + 8;
      monkeys[2]->items[0]->mods[5] = monkeys[2]->items[0]->mods[5] + 8;
      monkeys[2]->items[0]->mods[6] = monkeys[2]->items[0]->mods[6] + 8;
      monkeys[2]->items[0]->mods[7] = monkeys[2]->items[0]->mods[7] + 8;
      if (monkeys[2]->items[0]->mods[2] % monkeys[2]->d == 0) {
        monkeys[monkeys[2]->t]->items.push_back(monkeys[2]->items[0]);
      }
      else {
        monkeys[monkeys[2]->f]->items.push_back(monkeys[2]->items[0]);
      }
      monkeys[2]->items.erase(monkeys[2]->items.begin(), monkeys[2]->items.begin()+1);
    }
    
    while (monkeys[3]->items.size()) {
      ++monkeys[3]->count;
      monkeys[3]->items[0]->mods[0] = monkeys[3]->items[0]->mods[0] + 4;
      monkeys[3]->items[0]->mods[1] = monkeys[3]->items[0]->mods[1] + 4;
      monkeys[3]->items[0]->mods[2] = monkeys[3]->items[0]->mods[2] + 4;
      monkeys[3]->items[0]->mods[3] = monkeys[3]->items[0]->mods[3] + 4;
      monkeys[3]->items[0]->mods[4] = monkeys[3]->items[0]->mods[4] + 4;
      monkeys[3]->items[0]->mods[5] = monkeys[3]->items[0]->mods[5] + 4;
      monkeys[3]->items[0]->mods[6] = monkeys[3]->items[0]->mods[6] + 4;
      monkeys[3]->items[0]->mods[7] = monkeys[3]->items[0]->mods[7] + 4;
      if (monkeys[3]->items[0]->mods[3] % monkeys[3]->d == 0) {
        monkeys[monkeys[3]->t]->items.push_back(monkeys[3]->items[0]);
      }
      else {
        monkeys[monkeys[3]->f]->items.push_back(monkeys[3]->items[0]);
      }
      monkeys[3]->items.erase(monkeys[3]->items.begin(), monkeys[3]->items.begin()+1);
    }
    
    while (monkeys[4]->items.size()) {
      ++monkeys[4]->count;
      monkeys[4]->items[0]->mods[0] = monkeys[4]->items[0]->mods[0] + 3;
      monkeys[4]->items[0]->mods[1] = monkeys[4]->items[0]->mods[1] + 3;
      monkeys[4]->items[0]->mods[2] = monkeys[4]->items[0]->mods[2] + 3;
      monkeys[4]->items[0]->mods[3] = monkeys[4]->items[0]->mods[3] + 3;
      monkeys[4]->items[0]->mods[4] = monkeys[4]->items[0]->mods[4] + 3;
      monkeys[4]->items[0]->mods[5] = monkeys[4]->items[0]->mods[5] + 3;
      monkeys[4]->items[0]->mods[6] = monkeys[4]->items[0]->mods[6] + 3;
      monkeys[4]->items[0]->mods[7] = monkeys[4]->items[0]->mods[7] + 3;
      if (monkeys[4]->items[0]->mods[4] % monkeys[4]->d == 0) {
        monkeys[monkeys[4]->t]->items.push_back(monkeys[4]->items[0]);
      }
      else {
        monkeys[monkeys[4]->f]->items.push_back(monkeys[4]->items[0]);
      }
      monkeys[4]->items.erase(monkeys[4]->items.begin(), monkeys[4]->items.begin()+1);
    }
    
    while (monkeys[5]->items.size()) {
      ++monkeys[5]->count;
      monkeys[5]->items[0]->mods[0] = monkeys[5]->items[0]->mods[0] + 5;
      monkeys[5]->items[0]->mods[1] = monkeys[5]->items[0]->mods[1] + 5;
      monkeys[5]->items[0]->mods[2] = monkeys[5]->items[0]->mods[2] + 5;
      monkeys[5]->items[0]->mods[3] = monkeys[5]->items[0]->mods[3] + 5;
      monkeys[5]->items[0]->mods[4] = monkeys[5]->items[0]->mods[4] + 5;
      monkeys[5]->items[0]->mods[5] = monkeys[5]->items[0]->mods[5] + 5;
      monkeys[5]->items[0]->mods[6] = monkeys[5]->items[0]->mods[6] + 5;
      monkeys[5]->items[0]->mods[7] = monkeys[5]->items[0]->mods[7] + 5;
      if (monkeys[5]->items[0]->mods[5] % monkeys[5]->d == 0) {
        monkeys[monkeys[5]->t]->items.push_back(monkeys[5]->items[0]);
      }
      else {
        monkeys[monkeys[5]->f]->items.push_back(monkeys[5]->items[0]);
      }
      monkeys[5]->items.erase(monkeys[5]->items.begin(), monkeys[5]->items.begin()+1);
    }
    
    while (monkeys[6]->items.size()) {
      ++monkeys[6]->count;
      monkeys[6]->items[0]->mods[0] = monkeys[6]->items[0]->mods[0] + 7;
      monkeys[6]->items[0]->mods[1] = monkeys[6]->items[0]->mods[1] + 7;
      monkeys[6]->items[0]->mods[2] = monkeys[6]->items[0]->mods[2] + 7;
      monkeys[6]->items[0]->mods[3] = monkeys[6]->items[0]->mods[3] + 7;
      monkeys[6]->items[0]->mods[4] = monkeys[6]->items[0]->mods[4] + 7;
      monkeys[6]->items[0]->mods[5] = monkeys[6]->items[0]->mods[5] + 7;
      monkeys[6]->items[0]->mods[6] = monkeys[6]->items[0]->mods[6] + 7;
      monkeys[6]->items[0]->mods[7] = monkeys[6]->items[0]->mods[7] + 7;
      if (monkeys[6]->items[0]->mods[6] % monkeys[6]->d == 0) {
        monkeys[monkeys[6]->t]->items.push_back(monkeys[6]->items[0]);
      }
      else {
        monkeys[monkeys[6]->f]->items.push_back(monkeys[6]->items[0]);
      }
      monkeys[6]->items.erase(monkeys[6]->items.begin(), monkeys[6]->items.begin()+1);
    }
    
    while (monkeys[7]->items.size()) {
      ++monkeys[7]->count;
      monkeys[7]->items[0]->mods[0] = monkeys[7]->items[0]->mods[0] * 3 % 5;
      monkeys[7]->items[0]->mods[1] = monkeys[7]->items[0]->mods[1] * 3 % 17;
      monkeys[7]->items[0]->mods[2] = monkeys[7]->items[0]->mods[2] * 3 % 7;
      monkeys[7]->items[0]->mods[3] = monkeys[7]->items[0]->mods[3] * 3 % 13;
      monkeys[7]->items[0]->mods[4] = monkeys[7]->items[0]->mods[4] * 3 % 19;
      monkeys[7]->items[0]->mods[5] = monkeys[7]->items[0]->mods[5] * 3 % 3;
      monkeys[7]->items[0]->mods[6] = monkeys[7]->items[0]->mods[6] * 3 % 11;
      monkeys[7]->items[0]->mods[7] = monkeys[7]->items[0]->mods[7] * 3 % 2;
      if (monkeys[7]->items[0]->mods[7] == 0) {
        monkeys[monkeys[7]->t]->items.push_back(monkeys[7]->items[0]);
      }
      else {
        monkeys[monkeys[7]->f]->items.push_back(monkeys[7]->items[0]);
      }
      monkeys[7]->items.erase(monkeys[7]->items.begin(), monkeys[7]->items.begin()+1);
    }
  }
  
  int max1 = -1;
  int max2 = -1;
  
  for (int i=0; i<monkeys.size(); ++i) {
    if (monkeys[i]->count > max1) {
      max2 = max1;
      max1 = monkeys[i]->count;
    }
    else if (monkeys[i]->count > max2) {
      max2 = monkeys[i]->count;
    }
  }
  cout << endl;
  cout << max1 << endl;
  cout << max2 << endl;

  return 0;
}

// 14314925001
