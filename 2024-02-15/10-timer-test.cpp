// Testing class timer
#include "timer.hpp"
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main()
{
  std::mt19937 e;
  std::uniform_int_distribution u;

  std::vector<int> nums (1000000);
  for (auto& n: nums) n = u(e);

  timer<std::chrono::milliseconds> my_timer;

  my_timer.start();
  std::sort(nums.begin(), nums.end());
  my_timer.stop();
  
  std::cout << my_timer.count() << " millseconds.\n";
}

