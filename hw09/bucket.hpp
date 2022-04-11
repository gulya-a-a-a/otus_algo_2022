template <typename T> struct Node {
  Node(T &value) : value{value}, next{nullptr} {}
  T value;
  Node *next;
};

template <typename T> T findMax(std::vector<T> &data) {
  T result{std::numeric_limits<T>::min()};
  const size_t N = data.size();
  for (size_t i = 0; i < N; ++i) {
    if (data[i] > result) {
      result = data[i];
    }
  }
  return result;
}

template <typename T>
void putIntoBuckets(std::vector<T> &data, T max,
                    std::vector<Node<T> *> &buckets) {
  size_t index{};
  const size_t N = data.size();
  for (size_t i = 0; i < N; ++i) {
    index = (data[i] * N) / (max + 1);
    Node<T> *newNode = new Node(data[i]);
    Node<T> *node = buckets[index];
    Node<T> *prev = buckets[index];
    while (node != nullptr && node->value < data[i]) {
      prev = node;
      node = node->next;
    }
    if (node == buckets[index]) {
      newNode->next = buckets[index];
      buckets[index] = newNode;
    } else {
      newNode->next = node;
      prev->next = newNode;
    }
  }
}

template <typename T> void bucketSort(std::vector<T> &data) {
  const size_t N = data.size();

  T max = findMax(data);

  std::vector<Node<T> *> buckets(N);
  putIntoBuckets(data, max, buckets);

  for (size_t i = 0, j = 0; i < N; ++i) {
    Node<T> *node = buckets[i];
    while (node != nullptr) {
      data[j] = node->value;
      node = node->next;
      ++j;
    }
  }
}