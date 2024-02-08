// Library <chrono> example: compute time to sort a vector
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

// abbreviate long names
using std::chrono::duration_cast;
using std::chrono::microseconds;

int main()
{
  // need some random data
  std::mt19937 e;
  std::uniform_int_distribution<int> u(1000,9999);
  std::vector<int> nums(1000); // 1000 ints
  for (auto& n: nums) n = u(e);

  // set up the clock
  std::chrono::steady_clock clock;

  // time the sorting
  auto start_time = clock.now();
  std::ranges::sort(nums);
  auto stop_time = clock.now();

  // compute the elapsed time
  auto diff_time = stop_time - start_time;
  std::cout << "The sorting took "
	    << duration_cast<microseconds>(diff_time).count()
	    << " microseconds.\n";
}

