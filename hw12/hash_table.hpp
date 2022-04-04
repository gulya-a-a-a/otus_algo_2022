#ifndef HASH_TABLE_H
#define HASH_TABLE_H

template <typename TKey, typename T>
class HashTable {
public:
  virtual ~HashTable() {}

  virtual void add(TKey &&key, T &&value) = 0;

  virtual const T &operator[](TKey &key) const = 0;

  virtual T &operator[](TKey &key) = 0;

  struct HashTableEntity {
    TKey key;
    T value;
    HashTableEntity *next;

    HashTableEntity(TKey &_key, T &_value)
        : key{_key}, value{_value}, next{nullptr} {}
  };
};

#endif