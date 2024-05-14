#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

struct vertex {
  std::string name;
};

using graph =
  std::map<vertex*, std::vector<vertex*>>;

int main()
{
  std::ifstream infile;
  infile.open("states.txt");
  if (not infile.is_open()) throw std::exception();

  /*
  // print all lines
  std::string line;
  while (std::getline(infile, line)) {
    std::cout << line << '\n';
  }
  */

  // ignore first four lines
  std::string line;
  for (int i=0; i<4; ++i) {
    std::getline(infile, line);
  }

  // print adjacency list representation
  while (std::getline(infile, line)) {
    std::istringstream instr(line);
    std::string state;
    instr >> state;
    std::cout << state << ": ";
    // the adj list
    while (instr >> state) {
      std::cout << state << ' ';
    }
    std::cout << '\n';
  }
}
