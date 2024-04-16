// Priority queue with custom less than
#include <queue>
#include <vector>
#include <iostream>

struct customLess {
  bool operator()(int a, int b) {
    return a > b; // play with this definition
  }
};

int main()
{
  std::priority_queue<int, std::vector<int>, customLess> Q;
  Q.push(1);
  Q.push(3);
  Q.push(5);
  Q.push(4);
  Q.push(2);

  while (Q.size() > 0) {
    
    std::cout << Q.top() << '\t';
    Q.pop();
  }

  std::cout << std::endl;
}
  
