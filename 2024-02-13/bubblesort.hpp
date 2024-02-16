// Bubble sort algorithm
#include <algorithm> // for std::swap

template <typename List>
void bubblesort(List& v)
{
  auto size = v.size();
  for (size_t i = 0; (i+1) < size; ++i) {
    for (size_t j = 0; (j+1) < size - i; ++j) {
      if (v[j] > v[j+1]) std::swap(v[j], v[j+1]);
    }
  }
}
