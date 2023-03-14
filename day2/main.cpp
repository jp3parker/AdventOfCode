
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

int score;

void win() { score += 6; }
void draw() { score += 3; }
void lose() { score += 0; }

void rock() { score += 1; }
void paper() { score += 2; }
void scissors() { score += 3; }


int main() {
  
  ifstream input;
  input.open("input.txt");
  
  string line;
  while (!input.eof()) {
    getline(input, line, '\n');
    if (line.size() > 0) {
      if (line[0] == 'A') { // rock
        if (line[2] == 'X') { // lose
          lose();
          scissors();
        }
        else if (line[2] == 'Y') { // draw
          draw();
          rock();
        }
        else { // Z - win
          win();
          paper();
        }
      }
      else if (line[0] == 'B') { // paper
        if (line[2] == 'X') { // lose
          lose();
          rock();
        }
        else if (line[2] == 'Y') { // draw
          draw();
          paper();
        }
        else { // Z - win
          win();
          scissors();
        }
      }
      else { // 'C' - scissors
        if (line[2] == 'X') { // lose
          lose();
          paper();
        }
        else if (line[2] == 'Y') { // draw
          draw();
          scissors();
        }
        else { // Z - win
          win();
          rock();
        }
      }
    }
  }
  
  cout << score << endl;

  return 0;
}
