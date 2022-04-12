#include <cassert>
#include <iostream>
#include <memory>
#include <sstream>

#include "hash_table_chaining.hpp"

template <typename TKey, typename T>
using HashTablePtr = std::unique_ptr<HashTable<TKey, T>>;

int main(int argc, char const *argv[]) {
  size_t count = 25;
  std::stringstream ss;

  HashTableChaining<std::string, int> ht;

  for (size_t i = 0; i < count; i++) {
    ss << i;
    ht.put(ss.str(), i);
    ss.str("");
  }
  auto result = ht["7"];
  assert(result.has_value() == true);
  assert(ht["7"].value() == 7);

  bool found = ht.containsKey("3");
  assert(found == true);

  auto removed = ht.remove("3");
  assert(removed.has_value() == true);
  assert(removed.value() == 3);

  found = ht.containsKey("3");
  assert(found == false);

  return EXIT_SUCCESS;
}
