#include "Set.hpp"
#include <iostream>

int main()
{
  Set X = {1,2,3};
  X.print();
  Set Y = {2,4,6};
  Y.print();
  X += Y;
  X.print(); // 1, 2, 3, 4, 6
  X ^= Y;
  X.print(); // expect 2 4 6
}
