// sort in reverse with function object
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

template <typename Num>
class my_less {
public:
  bool operator()(const Num& a, const Num& b) {
    return a > b; // NOTE: greater than
  }
};

int main()
{
  std::vector<int> nums = {1, 3, 5, 7, 9, 8, 6, 4, 2, 0};
  my_less<int> my_less_object;
  std::sort(nums.begin(), nums.end(), my_less_object);
  for (auto n: nums) {
    std::cout << n << '\t';
  }
  std::cout << std::endl;
}
