// Binary search tree basic examples
#include <iostream>
#include <random>

template <typename T>
struct tree_node {
  T key;
  tree_node *left = nullptr, *right = nullptr;
};

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

template <typename T>
void tree_inorder_traversal(const tree_node<T>* t)
{
  if (t == nullptr) return;
  tree_inorder_traversal(t->left);
  std::cout << t->key << '\n';
  tree_inorder_traversal(t->right);
}

int main()
{
  tree_node<int>* my_tree = nullptr; // empty tree
  
  // insert random data into the tree
  for (auto n: {5, 3, 7, 20, 10, 8, 4, 1}) {
    tree_insert(my_tree, n);
  }

  tree_inorder_traversal(my_tree);
}
