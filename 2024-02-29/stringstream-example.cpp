// Demonstrate input string stream and std::stoi (string to int)
#include <sstream>
#include <iostream>
#include <string>
#include <stack>

int main()
{
  std::istringstream in("I love math. -20");
  std::string word;
  in >> word;
  std::cout << word << std::endl; // "I"
  in >> word;
  std::cout << word << std::endl; // "love"
  in >> word;
  std::cout << word << std::endl; // "math."
  in >> word;
  std::cout << 1 + std::stoi(word) << std::endl; // -19
}
