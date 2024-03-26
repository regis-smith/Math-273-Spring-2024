#include <iostream>

struct node {
  int key;
  node* next = nullptr;
};

void list_print(node* front) {
  for (auto i = front; i != nullptr; i = i -> next) {
    std::cout << i -> key << '\t';
  }
  std::cout << std::endl;
}

int main()
{
  node* my_list = nullptr; // empty list

  // add a node
  node* a = new node {10};

  // link it to my_list
  my_list = a;

  // test
  list_print(my_list);

  // add another node
  node* b = new node {20};

  // link it to a
  a->next = b;

  // check
  list_print(my_list);

  // put 30 between the 10 and 20
  node* x = new node {30,b};

  my_list->next = x;
  // x->next = b;
  // check
  list_print(my_list);
}
