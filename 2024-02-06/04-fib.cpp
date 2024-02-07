// Fibonacci function -- iterative version
// Variables first, second, third always store
// three consecutive members of the sequence.
// Computing fib(46) should be nearly instantaneous.
#include <iostream>

int fib(int n)
{
  if (n == 0 or n == 1) return n;
  int first = 0, second = 1;
  int third = first + second;
  while (n - 2 > 0) {
    int old_first = first,
      old_second = second,
      old_third = third;
    first = old_second;
    second = old_third;
    third = old_second + old_third;
    --n;
  }
  return third;
}

int main()
{
  std::cout << "About to compute fib(20).\n"
	    << "fib(20) = " << fib(20) << ".\n";
  std::cout << "About to compute fib(46)." << std::endl
	    << "fib(46) = " << fib(46) << ".\n";
}
