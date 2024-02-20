#include <iostream>

template <typename T>
struct node {
  T key;
  node* next = nullptr;
};

template <typename T>
void list_print(node<T>* front) {
  for (auto i = front; i != nullptr; i = i -> next) {
    std::cout << i -> key << '\t';
  }
  std::cout << std::endl;
}

template <typename K>
void list_insert_before_front(node<K>*& list, const K& key)
{
  auto new_front = new node<K> {key, list};
  list = new_front;
}

template <typename K>
void list_remove_front(node<K>*& list)
{
  if (list == nullptr) return;
  auto old_front = list;
  list = list -> next;
  delete old_front;
}

template <typename K>
void list_insert_after_back(node<K>*& list, const K& key)
{
  auto new_node = new node<K> {key};
  if (list == nullptr) {
    list = new_node;
    return;
  }
  // find the last node
  node<K>* target_node = list;
  while (target_node->next != nullptr) {
    target_node = target_node->next;
  }
  target_node->next = new_node;
}

int main()
{
  node<char>* my_list = nullptr; // empty list
  list_insert_before_front(my_list, 'a');
  list_insert_before_front(my_list, 'b');
  list_insert_before_front(my_list, 'c');

  list_print(my_list);

  list_remove_front(my_list);

  list_print(my_list);

  list_insert_after_back(my_list, 'd');

  list_print(my_list);  
}
