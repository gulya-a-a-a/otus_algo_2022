#include <functional>

#include "hash_table.hpp"

template <typename TKey, typename T, typename HashFunc = std::hash<TKey>>
class HashTableChaining : public HashTable<TKey, T> {
  using TBase = HashTable<TKey, T>;
  using TEntity = typename TBase::HashTableEntity;
  T v;

public:
  HashTableChaining() : HashTable<TKey, T>(), mStorage{}, hash{HashFunc{}} {}

  void add(TKey &&key, T &&value) override {
    size_t hashCode = hash(key);
    size_t bucketIndex = hashCode % storageSize();

    TEntity *newNode = new TEntity(key, value),
            *currentNode = mStorage[bucketIndex],
            *prevNode = mStorage[bucketIndex];

    while (currentNode != nullptr) {
      prevNode = currentNode;
      currentNode = currentNode->next;
    }

    if (currentNode == mStorage[bucketIndex]) {
      mStorage[bucketIndex] = newNode;
      return;
    }

    prevNode->next = newNode;
  }

  const T &operator[](TKey &key) const override { return v; }

  T &operator[](TKey &key) override { return v; }

private:
  TEntity *mStorage[10];
  HashFunc hash;

  constexpr size_t storageSize() const {
    return (sizeof(mStorage) / sizeof(TEntity *));
  }
};
