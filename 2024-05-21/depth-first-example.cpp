#include "graph.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

auto adj(graph G, vertex* v) {
  return G[v];
}

void dft(graph& G, vertex* s)
{
  auto v = s;
  std::cout << "Passing by " << s->name << '\n';
  v->color = vertex::GREY;
  for (auto w: adj(G,v)) {
    if (w->color == vertex::WHITE) dft(G, w);
  }
  v->color = vertex::BLACK;
  std::cout << "Visiting " << v->name << ".\n";
}

int main()
{
  std::ifstream infile;
  infile.open("states.txt");
  if (not infile.is_open()) throw std::exception();

  // ignore first four lines
  std::string line;
  for (int i=0; i<4; ++i) {
    std::getline(infile, line);
  }

  std::map<std::string, vertex*> states;
  
  // first pass: get the state names
  while (std::getline(infile, line)) {
    std::istringstream instr(line);
    std::string state;
    instr >> state;
    states.insert({state, new vertex {state}});
    std::cout << "create vertex  for " << state << ".\n";
  }

  std::cout << "number of states is "
	    << states.size() << ".\n";

  infile.close();
  //redo
  infile.open("states.txt");
  if (not infile.is_open()) throw std::exception();

  // ignore first four lines
  //std::string line;
  for (int i=0; i<4; ++i) {
    std::getline(infile, line);
  }

  graph G;

  // second pass, do the adjacency lists
  while (std::getline(infile, line)) {
    std::istringstream instr(line);
    std::string state;
    instr >> state;
    auto vertex4state = states[state];
    G.insert({vertex4state,{}});
    while (instr >> state) {
      G[vertex4state].push_back(states[state]);
    }
  }

  infile.close();

  // check G
  for (const auto& p: G) {
    std::cout << p.first->name << ": ";
    for (const auto& v: p.second) {
     	std::cout << v->name << " ";
    }
    std::cout << "\n";
  }

  // insert vertices only in new graph
  graph H;
  for (const auto& p: G) {
    H.insert({p.first, {}});
  }
  
  dft(G,states["CA"]);
}
