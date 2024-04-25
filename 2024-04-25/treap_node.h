// A treap node class.  Priorities are randomly generated.
#pragma once
#include <functional>
#include <random>

template <typename K>
struct treap_node {
  K key;
  long int priority;
  treap_node *left = nullptr, *right = nullptr;
  // constructor takes a key and generates a random priority
  treap_node(const K& key): key {key} {
    std::uniform_int_distribution<long int> u;
    priority = u(e);
  }
private:
  inline static std::mt19937 e {}; // "inline" allows initialization
                                   // of static member inside the class
};

template <typename K>
void rotate_right(treap_node<K>*& node)
{
  auto copy = node->left;
  node->left = node->left->right;
  copy->right = node;
  node = copy;
}

template <typename K>
void rotate_left(treap_node<K>*& node)
{
  auto copy = node->right;
  node->right = node->right->left;
  copy->left = node;
  node = copy;
}


template <typename K>
void treap_insert(treap_node<K>*& root, const K& key)
{
  if (root == nullptr) {
    root = new treap_node<K>(key);
    return;
  }
  if (key < root->key) {
    treap_insert(root->left, key);
    if (root->priority < root->left->priority) rotate_right(root);
  }
  else if (key > root->key) {
    treap_insert(root->right, key);
    if (root->priority > root->right->priority) rotate_left(root);
  }
  else { } // key already in the treap
}

template <typename K>
void treap_remove_node(treap_node<K>*& root)
{
  // easy case: leaf node
  if (root == nullptr or root->left == root->right) {
    delete root;
    root = nullptr;
    return;
  }
  // parent with one child only
  else if (root->left == nullptr) {
    rotate_left(root);
    treap_remove_node(root->left);
  }
  else if (root->right == nullptr) {
    rotate_right(root);
    treap_remove_node(root->right);
  }
  // parent with two children
  else {
    auto left_priority = root->left->priority;
    auto right_priority = root->right->priority;
    if (left_priority > right_priority) {
      rotate_right(root);
      treap_remove_node(root->right);
    }
    else {
      rotate_left(root);
      treap_remove_node(root->left);
    }
  }
}

template <typename K>
void treap_delete(treap_node<K>*& root, const K& key)
{
  if (root == nullptr) return;
  if (root->key == key) treap_remove_node(root);
  else if (key < root->key) treap_delete(root->left, key);
  else if (key > root->key) treap_delete(root->right, key);
  else { /* not found */ }
}

