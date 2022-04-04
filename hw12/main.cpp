#include <iostream>
#include <memory>

#include "hash_table_chaining.hpp"

template <typename TKey, typename T>
using HashTablePtr = std::unique_ptr<HashTable<TKey, T>>;

int main(int argc, char const *argv[]) {
  HashTableChaining<std::uint16_t, int> ht;

  size_t count = 20;

  srand(time(nullptr));
  for (size_t i = 0; i < count; i++) {
    ht.add(i, rand() % count);
  }

  return EXIT_SUCCESS;
}
