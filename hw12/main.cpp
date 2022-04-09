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
  if (result.has_value()) {
    std::cout << ht["7"].value() << '\n';
  }

  bool found = ht.containsKey("3");

  auto removed = ht.remove("3");

  found = ht.containsKey("3");

  return EXIT_SUCCESS;
}
