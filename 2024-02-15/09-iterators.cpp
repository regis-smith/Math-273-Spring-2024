#include <iostream>
#include <vector>
#include <string>

int main()
{
  int nums[] = {1,2,3,5};
  for (int i=0; i<4; ++i) std::cout << nums[i] << '\n';

  // visit with pointer arithmetic
  for (int i=0; i<4; ++i) std::cout << *(nums+i) << '\n';

  std::vector<int> nums1 = {1,2,3,5};

  // visit with iterators
  for (std::vector<int>::iterator i = nums1.begin(); i != nums1.end(); ++i)
    std::cout << *i << '\n';

  // visit with iterators (using auto instead of the long name) 
  for (auto i = nums1.begin(); i != nums1.end(); ++i)
    std::cout << *i << '\n';

  // visit with reverse iterators
  for (auto i = nums1.rbegin(); i != nums1.rend(); ++i)
    std::cout << *i << '\n';

  // print a string in reverse-- std::string has iterators too!
  std::string word = "hello";
  for (auto i = word.rbegin(); i != word.rend(); ++i)
    std::cout << *i << '\n';
  
  // print a string in reverse-- std::string has iterators too!
  for (auto i = word.rbegin() + 2 ; i != word.rend(); ++i)
    std::cout << *i << '\n';

  
}
