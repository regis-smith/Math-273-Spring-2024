#include <map>
#include <iostream>
#include <utility>
#include <string>
#include <vector>

struct vertex {
  std::string name;
};

using graph =
  std::map<vertex*, std::vector<vertex*>>;

int main()
{
  auto A = new vertex {"A"};
  auto B = new vertex {"B"};
  auto C = new vertex {"C"};

  graph G = { {A, {B,C}},
	      {B, {C}},
	      {C, {A,C}}
  };

  // visit vertices
  for (auto p: G) {
    std::cout << p.first->name << '\t';
  }
  std::cout << '\n';

  // write down adjacency list
  for (auto p: G) {
    // print vertex and a colon:
    std::cout << p.first->name << ": ";
    // print adj list
    for (auto v: p.second) {
      std::cout << v->name << ' ';
    }
    std::cout << '\n';
  }
  }
