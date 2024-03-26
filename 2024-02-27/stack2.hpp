// Stack with arbitrary sized array as storage
#pragma once
#include <iostream>

template <typename T, int CAPACITY>
class stack {
public:
  void push(const T &);
  void pop();
  T& top();
  int size() const;
private:
  T storage[CAPACITY];
  int top_index = -1;
  const int capacity = CAPACITY;
};

template <typename T, int CAPACITY>
void stack<T, CAPACITY>::push(const T &x)
{
  if (top_index == CAPACITY-1) {
    std::cout << "Stack is full.\n";
    return;
  }
  storage[++top_index] = x;
}

template <typename T, int CAPACITY>
void stack<T,CAPACITY>::pop()
{
  if (top_index == -1) {
    std::cout << "Stack is empty.  Can not pop.\n";
    return;
  }
  --top_index;
}

template <typename T, int CAPACITY>
int stack<T,CAPACITY>::size() const
{
  return top_index+1;
}

template <typename T, int CAPACITY>
T& stack<T,CAPACITY>::top()
{
  if (top_index == -1) {
    std::cout << "Empty stack has no top.\n";
    throw std::exception(); // nothing to return
  }
  return storage[top_index];
}
