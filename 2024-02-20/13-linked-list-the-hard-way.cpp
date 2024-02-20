// Manually create a linked list.
#include <iostream>

template <typename Key>
struct node {
  Key key;
  node* next = nullptr;
};

int main()
{
  // empty list is null pointer
  node<int>* my_list = nullptr;

  // create a node with new as front of my_list
  my_list = new node<int> {3};

  // create another node and link it to the front
  my_list->next = new node<int> {10};

  // create another node and insert after the last node
  my_list->next->next = new node<int> {8};

  // insert a node with 20 between the last two (with 10 and 8)
  auto node8 = my_list->next->next;
  my_list->next->next = new node<int> {20};
  my_list->next->next->next = node8;

  // check the contents
  for (auto i = my_list; i != nullptr; i = i->next) {
    std::cout << i->key << std::endl;
  }

  // free the nodes in the list
  auto i = my_list;
  while (i != nullptr) {
    auto target = i;
    i = i->next;
    delete target;
  }
  my_list = nullptr; // important
}
