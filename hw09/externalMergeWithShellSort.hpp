template <typename T> void shellSortChunk(int p, int r, std::fstream &data) {
  int range = r - p + 1;
  std::vector<T> vData(range);

  data.seekp(p * sizeof(T));
  data.read(reinterpret_cast<char *>(vData.data()), range * sizeof(T));

  shellSortPapernov(vData);

  data.seekg(p * sizeof(T));
  data.write(reinterpret_cast<char *>(vData.data()), range * sizeof(T));
}

template <typename T>
void mergeSortWithShell(int p, int r, std::fstream &data, std::fstream &tmp) {
  if (r - p < 33) {
    shellSortChunk<T>(p, r, data);
    return;
  }

  int q = (p + r) / 2;
  mergeSortWithShell<T>(p, q, data, tmp);
  mergeSortWithShell<T>(q + 1, r, data, tmp);
  merge<T>(p, q, r, data, tmp);
}

template <typename T> void mergeSortWithShell(std::fstream &data) {
  std::fstream tmp("tests/tmp.bin", tmp.binary | tmp.in | tmp.out | tmp.trunc);

  data.seekg(0, data.end);
  size_t fileLength = data.tellg();
  data.seekg(0, data.beg);
  mergeSortWithShell<T>(0, fileLength / sizeof(T) - 1, data, tmp);
}