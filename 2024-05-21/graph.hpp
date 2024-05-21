// Basic graph type for algorithm demonstrations.
// Uses the adjacency list representation, so a
// graph is a std::map of vertex*, vector<vertex*> pairs.
#ifndef MATH273GRAPH
#define MATH273GRAPH

#include <map>
#include <string>
#include <vector>

struct vertex {
  std::string name;
  enum {WHITE, GREY, BLACK} color = WHITE;
};

using graph = std::map<vertex*, std::vector<vertex*>>;

#endif

/*
  Example graph construction

  // Create vertices
  auto A = new vertex {"A"};
  auto B = new vertex {"B"};
  auto C = new vertex {"C"};
  auto D = new vertex {"D"};
  auto E = new vertex {"E"};


  // Construct the graph
  graph G = { {A, {A, B}},
              {B, {B, D}},
	      {C, {A, D}},
	      {D, {}},
	      {E, {B, D}}
      };
*/
