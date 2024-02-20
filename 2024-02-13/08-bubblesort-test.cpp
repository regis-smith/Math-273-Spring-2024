#include "bubblesort.hpp"
#include <iostream>
#include <random>
#include <vector>

int main()
{
  // set up the random sequence generator
  std::mt19937 e;
  std::uniform_int_distribution<int> u(10,99);

  // store random sequence in a vector
  std::vector<int> nums (20);
  for (auto& n: nums) n = u(e);

  // print the vector ("before")
  std::cout << "Before sorting: ";
  for (const auto& n: nums) std::cout << n << " ";
  std::cout << '\n';

  // sort
  bubblesort(nums);
  
  // print the vector ("after")
  std::cout << "After sorting: ";
  for (const auto& n: nums) std::cout << n << " ";
  std::cout << '\n';
}
