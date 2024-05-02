#include <cstddef>
#include <iostream>

template <typename T>
struct node {
  T key;
  node *next = nullptr;
  node *prev = nullptr;
};

template <typename T>
node<T>* push_front(node<T>*& front, const T& key) {
  node<T>* new_node = new node<int> {key, front->next, front};
  front->next->prev = new_node;
  front->next = new_node;
  return new_node;
}

template <typename T>
node<T>* push_back(node<T>*& back, const T& key)
{
  node<T>* new_node = new node<int> {key, back, back->prev};
  back->prev->next = new_node;
  back->prev = new_node;
  return new_node;
}

int main()
{
  /*
  auto front = new node<int> {}; // fake node
  auto back = new node<int> {}; // fake node

  // 0 <----  front ---->
  //                <--- back ---> 0

  // construct empty list
  front->next = back;
  back->prev = front;

  // inset x into list
  auto x = new node<int> {7, back, front};
  front->next = x;
  back->prev = x;

  // test
  for (auto i = front->next; i != back; i = i->next) {
    std::cout << i->key << '\n';
  }

  // insert y into the list
  auto y = new node<int> {3, front->next, front};
  front->next->prev = y;
  front->next = y;
  // use this to define push_front
  
  // test
  for (auto i = front->next; i != back; i = i->next) {
    std::cout << i->key << '\n';
  }

  for (int n: {1,2,3,4,5,6,7,8,9}) {
    push_front(front, n);
  }

  // test
  for (auto i = front->next; i != back; i = i->next) {
    std::cout << i->key << '\n';
  }

  for (int n: {10, 20, 30, 40}) {
    push_back(back, n);
  }

  // test
  for (auto i = front->next; i != back; i = i->next) {
    std::cout << i->key << '\n';
  }
*/
  // new list
  auto front_end = new node<int> {};
  auto back_end = new node<int> {};
  front_end->next = back_end;
  back_end->prev = front_end;

  for (int n: {5,5,5}) push_back(back_end,n);
  auto p = push_back(back_end, 5);
  for (int n: {15, 35, 25}) push_back(back_end, n);

  /*  // test
  for (auto i = front_end->next; i != back_end; i = i->next) {
    std::cout << i->key << '\n';
  }
  */
  // should be 5
  std::cout << p->key << std::endl;


  // find where to insert p
  auto target = p->prev;
  while (target != front_end and target->key > p->key) {
    target = target->prev;
  }

  // insert after target
  p->prev->next = p->next;
  p->next->prev = p->prev;
  target->next->prev = p;
  p->next = target->next;
  target->next = p;
  p->prev = target;

  // test
  for (auto i = front_end->next; i != back_end; i = i->next) {
    std::cout << i->key << '\n';
  }

  // insertion sort
  // 3 5 2 7 6 8 7
  // start at the second item in list
  // run this insertion code on it and the front
  // repeat for remaiing members of list
  
}
