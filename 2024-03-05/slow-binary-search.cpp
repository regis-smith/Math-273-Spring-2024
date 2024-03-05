// Slow down binary search so we can compare running times
#include "timer.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

// Function object to slow down comparisons
template <typename Num>
class my_less {
public:
  bool operator()(const Num& a, const Num& b) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // pause
    return a < b;
  }
};

int main()
{
  std::mt19937 e;
  std::uniform_int_distribution<int> u;

  // Search containers of the following sizes
  auto sizes = {10000000, 20000000, 40000000, 80000000, 16000000, 32000000};
  for (auto size: sizes) {
    
    std::vector<int> nums;
    nums.resize(size);
    for (auto& n: nums) n = 2*u(e); // store even ints only

    my_less<int> slow_less;
    timer<std::chrono::milliseconds> my_timer;
    my_timer.start();
    // search for an odd int, which will not be found
    std::binary_search(nums.begin(), nums.end(), 2*u(e)+1, slow_less);
    my_timer.stop();

    std::cout << "Size: " << nums.size() << "\tRunning time: "
	      << my_timer.count() << "ms\tRatio: "
	      << my_timer.count() / log(nums.size()) <<'\n';
  }
}
