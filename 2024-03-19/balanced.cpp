#include <cmath>
#include <iostream>
#include "tree_node.hpp"
#include <random>

int main()
{
  std::mt19937 e;
  std::uniform_int_distribution<int> u;

  tree_node<int>* my_tree = nullptr;
  for (int i=0; i<100000; ++i) {
    tree_insert(my_tree, u(e));
  }

  std::cout << "size: 100000\theight: "
	    << tree_height(my_tree)
	    << std::endl;

  for (int i=0; i<100000; ++i) {
    tree_insert(my_tree, u(e));
  }

  std::cout << "size: 200000\theight: "
	    << tree_height(my_tree)
	    << std::endl;
}
