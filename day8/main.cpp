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


struct tree {
  bool visible;
  int height;
};


int main() {
  
  ifstream input;
  input.open("input.txt");
  
  vector< vector<tree> > trees;
  
  string line;
  getline(input, line, '\n');
  while (line.length() > 0) {
    vector<tree> row;
    for (int i=0; i<line.length(); ++i) {
      tree x;
      x.visible = false;
      x.height = line[i] - '0';
      row.push_back(x);
    }
    trees.push_back(row);
    getline(input, line, '\n');
  }
  
  int highestScore = -1;
  for (int i=0; i<trees.size(); ++i) {
    for (int j=0; j<trees[i].size(); ++j) {
      int currentScore;
      int currentTreeHeight = trees[i][j].height;
      
      //look up
      int upTrees = 0;
      int upIndex = i - 1;
      while (upIndex >= 0 and trees[upIndex][j].height < trees[i][j].height) {
        ++upTrees;
        --upIndex;
      }
      if (upIndex >= 0 and trees[upIndex][j].height == trees[i][j].height) {
        ++upTrees;
      }
      currentScore = upTrees;
      
      //look right
      int rightTrees = 0;
      int rightIndex = j + 1;
      while (rightIndex < trees[i].size() and trees[i][rightIndex].height < trees[i][j].height) {
        ++rightTrees;
        ++rightIndex;
      }
      if (rightIndex < trees[i].size() and trees[i][rightIndex].height == trees[i][j].height) {
        ++rightTrees;
      }
      currentScore *= rightTrees;
      
      
      //look down
      int downTrees = 0;
      int downIndex = i + 1;
      while (downIndex < trees.size() and trees[downIndex][j].height < trees[i][j].height) {
        ++downTrees;
        ++downIndex;
      }
      if (downIndex < trees.size() and trees[downIndex][j].height == trees[i][j].height) {
        ++downTrees;
      }
      currentScore *= downTrees;
      
      //look left
      int leftTrees = 0;
      int leftIndex = j - 1;
      while (leftIndex >= 0 and trees[i][leftIndex].height < trees[i][j].height) {
        ++leftTrees;
        --leftIndex;
      }
      if (leftIndex >= 0 and trees[i][leftIndex].height == trees[i][j].height) {
        ++leftTrees;
      }
      currentScore *= leftTrees;
      
      if (currentScore > highestScore) {
        highestScore = currentScore;
      }
      
    }
  }
  
  cout << highestScore << endl;
  
  

  return 0;
}
