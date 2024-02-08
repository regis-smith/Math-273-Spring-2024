// Euclid's greatest common divisor function
// Iterative version
#include <iostream>

int gcd(int m, int n)
{
  while (m != n) { // Step 1: check if m equals n.
    // Step 2: Replace the larger of m,n with their difference.
    if (m > n) {
      m = m - n;
    }
    else {
      n = n - m;
    }
  } // Step 3: Go to Step 1--beginning of while statement
  return m;
}

int main()
{
  std::cout << "The GCD of 250 and 350 is "
	    << gcd(250,350) << ".\n";
}
