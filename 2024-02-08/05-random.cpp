// Quick recipe for generating random number sequences
// Choose a generator e, a distribution u, and then
// u(e) returns the next number in the sequence.
#include <iostream>
#include <random>

int main()
{
  std::mt19937 e; // Mersenne twister engine
  std::uniform_int_distribution<int> u(10,99);

  for (int i=0; i<10; ++i) {
    std::cout << u(e) << '\n';
  }
}
