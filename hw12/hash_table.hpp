#ifndef HASH_TABLE_H
#define HASH_TABLE_H

/**
 * The hash table abstract class.
 *
 * @tparam TKey : The type of keys to match records.
 * @tparam TValue : The value type of the entries.
 */
template <typename TKey, typename T>

class HashTable {
public:
  virtual ~HashTable() {}

  /**
   * Adds the value into the HashTable, mapped by the passed key.
   *
   * @param  {TKey} &key     : The key used to locate the value.
   * @param  {TValue} &value : The value to be stored in the table.
   */
  virtual void put(TKey &&key, T &&value) = 0;

  /**
   * An index operator to retrieve a value from a table using the supplied key.
   *
   * @param  {TKey} key               : The key to search for the value.
   * @return {std::optional<TValue>}  : An optional object that stores null if
   * there is no such key in the table, and the value if it exists.
   */
  virtual std::optional<T> operator[](const TKey &key) const = 0;

  /**
   * Check is the supplied key is presented in the table.
   *
   * @param  {TKey} key : The key to search for.
   * @return {bool}     : True if the key is exists, false if not.
   */
  virtual bool containsKey(TKey &&key) const = 0;
};

#endif