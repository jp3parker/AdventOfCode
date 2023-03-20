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

bool diff(char a, char b, char c, char d,
          char e, char f, char g, char h,
          char i, char j, char k, char l,
          char m, char n) {
  if (a != b and a != c and a != d and a != e and a != f and a != g and a != h and a != i and a != j and a != k and a != l and a != m and a != n and
                 b != c and b != d and b != e and b != f and b != g and b != h and b != i and b != j and b != k and b != l and b != m and b != n and
                            c != d and c != e and c != f and c != g and c != h and c != i and c != j and c != k and c != l and c != m and c != n and
                                       d != e and d != f and d != g and d != h and d != i and d != j and d != k and d != l and d != m and d != n and
                                                  e != f and e != g and e != h and e != i and e != j and e != k and e != l and e != m and e != n and
                                                             f != g and f != h and f != i and f != j and f != k and f != l and f != m and f != n and
                                                                        g != h and g != i and g != j and g != k and g != l and g != m and g != n and
                                                                                   h != i and h != j and h != k and h != l and h != m and h != n and
                                                                                              i != j and i != k and i != l and i != m and i != n and
                                                                                                         j != k and j != l and j != m and j != n and
                                                                                                                    k != l and k != m and k != n and
                                                                                                                               l != m and l != n and
                                                                                                                                          m != n
  ) return true;
  return false;
}

int main() {
  
  ifstream input;
  input.open("input.txt");
  
  string line;
  getline(input, line, '\n');
  
  char a = line[0];
  char b = line[1];
  char c = line[2];
  char d = line[3];
  char e = line[4];
  char f = line[5];
  char g = line[6];
  char h = line[7];
  char i = line[8];
  char j = line[9];
  char k = line[10];
  char l = line[11];
  char m = line[12];
  char n = line[13];
  int index = 13;
  
  while (!diff(a,b,c,d,e,f,g,h,i,j,k,l,m,n)) {
    a = b;
    b = c;
    c = d;
    d = e;
    e = f;
    f = g;
    g = h;
    h = i;
    i = j;
    j = k;
    k = l;
    l = m;
    m = n;
    n = line[++index];
  }
  cout << index << endl;
  
  

  return 0;
}
