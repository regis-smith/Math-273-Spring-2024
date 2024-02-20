// Exercise: The list, my_list, looks like
//                2 -> 10 -> 15 -> 5
// Write a few statements to insert a node with 17 in the middle,
// so my_list looks like
//              2 -> 10 -> 17 -> 15 -> 5
// Step 1: Draw a picture of the actions you will take.
#include <iostream>

template <typename Key>
struct node {
  Key key;
  node* next = nullptr;
};

// Test function to print a list
template <typename T>
void print_list(const node<T>* front)
{
  for (auto i = front; i != nullptr; i = i->next) {
    std::cout << i->key << '\t';
  }
  std::cout << std::endl;
}

int main()
{
  // This convoluted code constructs the initial list.
  // You can ignore for now and assume it works.
  auto init_list = {5,15,10,2};
  node<int>* my_list = nullptr; // empty list
  for (auto key: init_list) {
    auto new_node = new node<int> {key};
    new_node->next = my_list;
    my_list = new_node;
  }

  print_list(my_list);

  // Write a few lines to insert 17 in the middle
  // a 
  // few 
  // lines
  // of
  // code

  // check your answer
  print_list(my_list);
}
