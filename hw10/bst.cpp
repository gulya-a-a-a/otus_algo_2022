#include <cassert>
#include <iostream>

#include "bst.hpp"

int main(int argc, char const *argv[]) {
  BinarySearchTree<int, int> bst;

  bst.insert(10, 5);
  bst.insert(15, 5);
  bst.insert(8, 5);
  bst.insert(1, 5);
  bst.insert(12, 5);

  bool found = bst.searchIterative(15);
  assert(found == true);

  bst.remove(15);
  found = bst.searchIterative(15);
  assert(found == false);

  found = bst.searchIterative(22);
  assert(found == false);

  return EXIT_SUCCESS;
}
