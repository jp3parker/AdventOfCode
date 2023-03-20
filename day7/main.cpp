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

struct dir {
  string name;
  int size;
  dir* parent;
  vector<dir*> childDirs;
};

int parseFile(string& line) {
  int i=0;
  while (line[i] != ' ') {
    ++i;
  }
  return stoi(line.substr(0, i));
}

void goUpTree(int size, dir* directory) {
  dir* current = directory;
  while (current) {
    current->size += size;
    current = current->parent;
  }
}

int best = INT_MAX;
int sizeToDelete;
void recurSeach(dir* root, int level) {
  if (root->size >= sizeToDelete and root->size < best) {
    best = root->size;
  }
  for (int i=0; i<root->childDirs.size(); ++i) {
    recurSeach(root->childDirs[i], level+1);
  }
}

int times = 0;
int main() {
  
  ifstream input;
  input.open("input.txt");
  
  dir* root = new dir;
  root->name = "/";
  root->size = 0;
  root->parent = NULL;
  dir* current = root;
  
  string line;
  getline(input, line, '\n');
  
  while (line.length() > 0) {
    
    if (line.compare("$ ls") == 0) {
      getline(input, line, '\n');
      if (line.length() > 0 and line[0] != '$') {
        do {
          if (line[0] == 'd') {
            dir* childDirectory = new dir;
            childDirectory->name = line.substr(4, line.length() - 4);
            childDirectory->size = 0;
            childDirectory->parent = current;
            current->childDirs.push_back(childDirectory);
          }
          else {
            goUpTree(parseFile(line), current);
          }
          getline(input, line, '\n');
        } while (line.length() > 0 and line[0] != '$');
      }
      
      
    }
    
    
    else if (line.compare("$ cd ..") == 0) {
      current = current->parent;
      getline(input, line, '\n');
    }
    
    
    else if (line.compare("$ cd /") == 0) {
      current = root;
      getline(input, line, '\n');
    }
    
    
    else if (line.substr(0, 5).compare("$ cd ") == 0) {
      string name = line.substr(5, line.length() - 5);
      for (int i=0; i<current->childDirs.size(); ++i) {
        if (name.compare(current->childDirs[i]->name) == 0) {
          current = current->childDirs[i];
          break;
        }
      }
      getline(input, line, '\n');
    }
    
    else {
      cout << "uncaught command" << endl;
    }
  }
  
  int totalSize = 70000000;
  int sizeNeeded = 30000000;
  int sizeAvailavle = totalSize - root->size;
  sizeToDelete = sizeNeeded - sizeAvailavle;
  
  
  
  recurSeach(root, 0);
  cout << root->size << endl;
  cout << sizeToDelete << endl;
  cout << best << endl;

  return 0;
}
