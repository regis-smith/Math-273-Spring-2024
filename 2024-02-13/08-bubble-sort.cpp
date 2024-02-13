// Template function Bubble sort
#include <iostream>
#include <utility> // for std::swap
#include <vector>

template <typename T>
void bubble_sort(std::vector<T>& items)
{
  auto size = items.size();
  for (size_t i=0; (i+1) < size; ++i) {
    for (size_t j=0; (j+1) < size; ++j) {
      if (items[j] > items[j+1]) std::swap(items[j], items[j+1]);
    }
  }
}

int main()
{
	std::vector<char> letters = {'e', 'a', 'c', 'b', 'd'};
	bubble_sort(letters);
	for (auto l: letters) std::cout << l;
	std::cout << std::endl;
}
