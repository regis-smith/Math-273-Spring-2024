// template function example
#include <iostream>
#include <vector>

// Swap two items of the same type T.
// This works as long as the given usage is valid for the type.
// Note:  There is a std::swap in the <utilities> library. 
template <typename T>
void swap(T& x, T& y)
{
  T tmp = x;
  x = y;
  y = tmp;
}

int main()
{
  // Swap two ints
  int a = 4, b = 7;
  std::cout << "Before: a = " << a
	    << "; b = " << b << '\n';
  swap(a,b);
  std::cout << "After: a = " << a
	    << "; b = " << b << '\n';

  // Swap two vectors
  std::vector<char> first3 = {'a','b','c'};
  std::vector<char> last3 = {'x', 'y', 'z'};
  std::cout << "Before:\nVector first3 has ";
  for (auto c: first3) std::cout << c;
  std::cout << "\nVestor last3 has ";
  for (auto c: last3) std::cout << c;
  std::cout << std::endl;
  
  swap(first3,last3);
  std::cout << "After:\nVector first3 has ";
  for (auto c: first3) std::cout << c;
  std::cout << "\nVector last3 has ";
  for (auto c: last3) std::cout << c;
  std::cout << std::endl;
  
}
