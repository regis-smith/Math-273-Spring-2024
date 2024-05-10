// Slow O(n^2) "Heapsort" using std::make_heap
// You can replace make_heap in the last step below
// with "sift down" to get O(n log(n)) performance
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  std::vector<int> nums = {1,2,3,4,5,6,7,8,9,0};
  // scramble with std::shuffle
  std::mt19937 e;
  std::shuffle(nums.begin(), nums.end(), e);
  for (const auto n: nums) std::cout << n << " ";
  std::cout << '\n';

  // make it into a heap
  std::make_heap(nums.begin(), nums.end());
  for (const auto n: nums) std::cout << n << " ";
  std::cout << '\n';

  // heapsort O(n^2) using make_heap O(n)
  for (auto size = nums.size(); size > 1; --size) {
    std::iter_swap(nums.begin(), nums.begin()+size-1);
    std::make_heap(nums.begin(), nums.begin()+size-1); // REDO!
  }
  for (const auto n: nums) std::cout << n << " ";
  std::cout << '\n';
}
