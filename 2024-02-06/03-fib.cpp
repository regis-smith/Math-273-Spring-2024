// Fibonacci function -- slow recursion
// Computing fib(46) will be noticeably slow
// because of many redundant computations.
#include <iostream>

int fib(int n)
{
  if (n == 0 or n == 1) return n;
  else return fib(n-1) + fib(n-2);
}

int main()
{
  std::cout << "About to compute fib(20).\n"
	    << "fib(20) = " << fib(20) << ".\n";
  std::cout << "About to compute fib(46)." << std::endl
	    << "fib(46) = " << fib(46) << ".\n";
}

