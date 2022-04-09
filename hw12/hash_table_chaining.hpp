#include <functional>
#include <optional>

#include "hash_table.hpp"

/**
 * The hash table class that uses the chaining method to resolve collisions.
 *
 * @tparam TKey : The type of keys to match records.
 * @tparam TValue : The value type of the entries.
 * @tparam HashFunc : A function object for computing key hashes.
 */
template <typename TKey, typename TValue, typename HashFunc = std::hash<TKey>>
class HashTableChaining : public HashTable<TKey, TValue> {
  /**
   * Linked list entry that is used to store keys and values in table chainings.
   */
  struct HashTableEntry {
    TKey key;
    TValue value;
    HashTableEntry *next;

    HashTableEntry(TKey &_key, TValue &_value)
        : key{_key}
        , value{_value}
        , next{nullptr} {}
  };

  using TBase = HashTable<TKey, TValue>;
  using TEntry = HashTableEntry;

  static constexpr float DEFAULT_LOAD_FACTOR = 0.75f;
  static constexpr size_t DEFAULT_CAPACITY = 10ul;

public:
  HashTableChaining()
      : HashTable<TKey, TValue>()
      , mStorage{new TEntry *[DEFAULT_CAPACITY]}
      , hashCodeCalculator{HashFunc{}}
      , mCapacity{DEFAULT_CAPACITY}
      , mSize{0}
      , mThreshold{mCapacity * DEFAULT_LOAD_FACTOR} {}

  /**
   * Adds the value into the HashTable, mapped by the passed key.
   *
   * @param  {TKey} &key     : The key used to locate the value.
   * @param  {TValue} &value : The value to be stored in the table.
   */
  void put(TKey &&key, TValue &&value) override {
    size_t bucketIndex = hash(key);

    TEntry *currentNode = mStorage[bucketIndex];

    while (currentNode != nullptr) {
      if (currentNode->key == key) {
        currentNode->value = value;
        return;
      }
      currentNode = currentNode->next;
    }

    if (++mSize > mThreshold) {
      rehash();
      bucketIndex = hash(key);
    }

    TEntry *newNode = new TEntry(key, value);

    newNode->next = mStorage[bucketIndex];
    mStorage[bucketIndex] = newNode;
  }

  /**
   * An index operator to retrieve a value from a table using the supplied key.
   *
   * @param  {TKey} key               : The key to search for the value.
   * @return {std::optional<TValue>}  : An optional object that stores null if
   * there is no such key in the table, and the value if it exists.
   */
  std::optional<TValue> operator[](const TKey &key) const override {
    size_t bucketIndex = hash(key);

    TEntry *currentNode = mStorage[bucketIndex];

    while (currentNode != nullptr) {
      if (currentNode->key == key) {
        return {currentNode->value};
      }
      currentNode = currentNode->next;
    }

    return {};
  }

  /**
   * Removes the entry associated with the supplied key from the table.
   * @param  {TKey} key               : The key of the entry to be remove.
   * @return {std::optional<TValue>}  : An optional object that stores null if
   * there is no such key in the table, and the value if it exists.
   */
  std::optional<TValue> remove(const TKey &key) {
    size_t bucketIndex = hash(key);

    TEntry *currentNode = mStorage[bucketIndex], *prevNode = nullptr;

    while (currentNode != nullptr) {
      if (currentNode->key == key) {
        if (prevNode == nullptr) {
          mStorage[bucketIndex] = currentNode->next;
        } else {
          prevNode->next = currentNode->next;
        }
        TValue v = currentNode->value;
        delete currentNode;
        return {v};
      }
      prevNode = currentNode;
      currentNode = currentNode->next;
    }

    return {};
  }

  /**
   * Check is the supplied key is presented in the table.
   *
   * @param  {TKey} key : The key to search for.
   * @return {bool}     : True if the key is exists, false if not.
   */
  bool containsKey(TKey &&key) const override {
    size_t bucketIndex = hash(key);
    TEntry *currentNode = mStorage[bucketIndex];

    while (currentNode != nullptr) {
      if (currentNode->key == key) {
        return true;
      }
      currentNode = currentNode->next;
    }

    return false;
  }

private:
  TEntry **mStorage;
  HashFunc hashCodeCalculator;
  size_t mCapacity, mSize;
  float mThreshold;

  /**
   * Returns current capacity of the underlying storage.
   *
   * @return {size_t}  : Current storage capacity.
   */
  constexpr size_t storageCapacity() const { return mCapacity; }

  /**
   * Calculates hash for the supplied key using hash functions that was passed
   * as a template parameter and storage size.
   *
   * @param  {TKey} key : The key to calculate the hash.
   * @return {size_t}   : The resulted hash.
   */
  size_t hash(const TKey &key) const {
    return hashCodeCalculator(key) % storageCapacity();
  }

  /**
   * Increases the size of the underlying storage and recalculates the hashes
   * for all entries in it.
   */
  void rehash() {
    auto oldStorage = mStorage;
    size_t oldCapacity = mCapacity;
    mCapacity = (mCapacity * 2ul) + 1ul;
    mStorage = new TEntry *[mCapacity];
    mThreshold = mCapacity * DEFAULT_LOAD_FACTOR;

    for (int i = oldCapacity - 1; i >= 0; --i) {
      TEntry *entity = oldStorage[i];

      while (entity != nullptr) {
        int idx = hash(entity->key);
        TEntry *dest = mStorage[idx];

        if (dest != nullptr) {
          TEntry *next = dest->next;

          while (next != nullptr) {
            dest = next;
            next = dest->next;
          }
          dest->next = entity;

        } else {
          mStorage[idx] = entity;
        }

        TEntry *next = entity->next;
        entity->next = nullptr;
        entity = next;
      }
    }
  }
};
