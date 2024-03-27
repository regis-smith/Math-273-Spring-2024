// A function to convert a linked list to a circular linked list
#include <iostream>

template <typename T>
struct list_node {
  T key;
  list_node *next = nullptr;
};

template <typename T>
void make_circular(list_node<T>*& front)
{
  if (front == nullptr) return;
  auto copy = front;
  // move copy to the back
  while (copy->next != nullptr) {
    copy = copy->next;
  }
  // link the back to the front
  copy->next = front;
}

int main()
{
  // Create the list A -> B -> C -> 0
  auto A = new list_node<char> {'a'};
  auto B = new list_node<char> {'b'};
  auto C = new list_node<char> {'c'};
  A->next = B;
  B->next = C;

  make_circular(A);
  // Now the list is linked like this:
  //      A -> B -> C -> A -> ...
  // The loop below should be infinite
  for (auto i=A; i != nullptr; i = i->next)
    std::cout << i-> key;
}
