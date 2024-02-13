#include <iostream>

int main()
{
  int x = 10, y = 20;
  int *px = &x, *py = &y;
  int& rx = x;
  int& ry = y;
  std::cout << x << '\t' << y << '\n';
  rx = ry; // rx is x, ry is y, so same effect as x = y;
  ry += 10; // ry is y, so same effect as y += 10;
  std::cout << x << '\t' << y << '\n'; // here x is 20, y is 30
  *px += ry - x; // same as x += 10
  *py -= y + rx; // same as y -= 60;
  std::cout << x << '\t' << y << '\n';
}
