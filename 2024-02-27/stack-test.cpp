#include "stack.hpp"
#include <iostream>

int main()
{
  stack<int,5> s; // small capacity to test overflow/underflow
  for (int n: {1,2,3,4,5,6,7,8,9}) {
    s.push(n);
  }
  // empty the stack
  do {
    std::cout << "Top is now: " << s.top() << '\n';
    s.pop();
  } while (s.size() > 0);
  s.pop(); // try to pop empty stack
  std::cout << s.top(); // 
}
