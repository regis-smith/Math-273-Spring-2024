// NOT DONE!!!!!!!!!
// array class for educational purposes
#include <algorithm>
#include <stdexcept>

template <typename key_t>
struct node {
  key_t key;
  node* next = nullptr;
};

template <typename key_t>
class deque {
public:
  deque();
  deque(const deque&);
  deque& operator=(const deque&);
  ~deque();
  int size() const;
  void push_front(const key_t);
  void push_back(const key_t);
  void pop_front();
  void pop_back();
private:
  node<key_t> head;
  int count = 0;
};
