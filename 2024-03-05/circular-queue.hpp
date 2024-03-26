// A queue with a static array as circular buffer for storage
// push_back and pop_front are in O(1).
// Syntax: queue<int,1024> is a queue of ints with maximum
//         capacity 1024.
#pragma once
#include <stdexcept>

template <typename T, int CAPACITY>
class queue {
public:
  queue(std::initializer_list<T> init = {}) {for (auto x: init) push_back(x);}
  void push_back(const T&); // defined below
  void pop_front() {
    if (count < 1) throw std::length_error("Queue is empty.");
    else --count;
  }
  const T& front() const; // defined below
  const T& back() const { return storage[back_index]; }
  int size() const { return count; }
private:
  T storage[CAPACITY] = {0}; // all zeros
  int back_index = -1;
  int count = 0;
};

template <typename T, int CAPACITY>
void queue<T,CAPACITY>::push_back(const T& item)
{
  if (count >= CAPACITY) throw std::length_error("Queue is full."); 
  ++count;
  ++back_index;
  back_index %= CAPACITY;
  storage[back_index] = item;
}

template <typename T, int CAPACITY>
const T& queue<T,CAPACITY>::front() const
{
  int index = back_index + 1 - count;
  if (index < 0) index += CAPACITY;
  return storage[index];
}
