// Test a very, very, very basic Set class
#include <iostream>
#include <initializer_list>
#include <vector>

class Set {
public:
  Set (std::initializer_list<int> L = {});
  void operator+=(const Set&); // union
  void operator^=(const Set&); // intersection
  void print() const;
private:
  std::vector<int> storage;
};

Set::Set(std::initializer_list<int> L): storage {L}
{
}

void Set::operator^=(const Set& B)
{
  // do a nested for statement to find common set members
  std::vector<int> new_set;
  for (int a: storage) {
    for (int b: B.storage) {
      if (a == b) new_set.push_back(a);
    }
  }
  storage = new_set;
}

void Set::operator+=(const Set& B)
{
  // For every b in B, check if b is in the set, and if not, insert it
  for (const int b: B.storage) {
    bool is_member = false;
    // check if b is in storage
    for (auto a: storage) {
      if (a == b) {
	is_member = true;
      }
    }
    if (not is_member) storage.push_back(b);
  }
}

void Set::print() const {
  for (auto x: storage) {
    std::cout << x << '\t';
  }
  std::cout << std::endl;
}
