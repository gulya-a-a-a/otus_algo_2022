template <typename T>
void mergeSort(int p, int r, std::fstream &data, std::fstream &tmp) {
  if (p >= r) {
    return;
  }

  int q = (p + r) / 2;
  mergeSort<T>(p, q, data, tmp);
  mergeSort<T>(q + 1, r, data, tmp);
  merge<T>(p, q, r, data, tmp);
}

template <typename T> void mergeSort(std::fstream &data) {
  std::fstream tmp("tests/tmp.bin", tmp.binary | tmp.in | tmp.out | tmp.trunc);
  T val{};

  data.seekg(0, data.end);
  size_t fileLength = data.tellg();
  data.seekg(0, data.beg);
  mergeSort<T>(0, fileLength / sizeof(T) - 1, data, tmp);
}