// Compute running times of std::sort
// to show they are approximately C*n*log(n)
#include "timer.hpp"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

int main()
{
  // We'll sort this vector.
  std::vector<int> nums;

  // These are the sizes I used.  Adjust these
  // your computer is faster or slower.
  auto sizes =
    {10000000,20000000,30000000,
     40000000,50000000,60000000};

  // Set up the random generator and timer.
  std::mt19937 e;
  std::uniform_int_distribution<int> u;
  timer<std::chrono::milliseconds> my_timer;

  // The table header.
  std::cout << "size\t\ttime\tratio\n";

  for (auto size: sizes) {
    // Resize the vector and generate the random sequence.
    nums.resize(size);
    for (auto &n : nums) n = u(e);

    // Find running time of the sorting.
    my_timer.start();
    std::sort(nums.begin(), nums.end());
    my_timer.stop();

    // Print the next line in the table.
    std::cout << size << '\t' << my_timer.count()
	      << "ms\t"
	      << my_timer.count()/(size*log(size))
	      << '\n';
  }
}
