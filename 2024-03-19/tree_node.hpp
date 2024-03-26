#pragma once

#include <iostream>
#include <utility>

template <typename T>
struct tree_node {
  T key;
  tree_node *left = nullptr, *right = nullptr;
};

// height of empty tree is -1
// height of nonempty tree is 1 + max height of subtrees
template <typename K>
int tree_height(const tree_node<K>* t)
{
  if (t == nullptr) return -1;
  int left_height = tree_height(t->left);
  int right_height = tree_height(t->right);
  return 1 + std::max(left_height, right_height);
}

template <typename T>
void tree_insert(tree_node<T>*& t, const T& key)
{
  if (t == nullptr) {
    t = new tree_node<T> {key};
    return;
  }
  if (key < t->key) tree_insert(t->left, key);
  else tree_insert(t->right, key);
}
