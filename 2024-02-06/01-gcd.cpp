// Euclid's greatest common divisor function
// Input: Positive integers M and N
// Result: The greatest common divisor of M and N
// Step 1: If M=N the stop, for the GCD is M.
// Step 2: Replace the larger of M and N with
//         their (positive) difference.
// Step 3: Go to Step 1.

#include <iostream>

int gcd(int m, int n)
{
  // Step 1
  if (m == n) return m;
  // Step 2
  if (m > n) {
    m = m - n;
  }
  else {
    n = n - m;
  }
  // Step 3
  return gcd(m,n); // recursively to Step 1
}

int main()
{
  std::cout << "The GCD of 250 and 350 is "
	    << gcd(250,350) << ".\n";
}
