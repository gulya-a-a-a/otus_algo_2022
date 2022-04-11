template <typename T>
void merge(int p, int q, int r, std::fstream &data, std::fstream &tmp) {
  int a = p, b = q + 1, m = p;
  T aVal{}, bVal{}, tmpVal{};

  tmp.seekg(0);
  while (a <= q && b <= r) {
    data.seekp(a * sizeof(T));
    data >> aVal;
    data.seekp(b * sizeof(T));
    data >> bVal;

    if (aVal <= bVal) {
      tmp << aVal;
      ++a;
    } else {
      tmp << bVal;
      ++b;
    }
  }

  while (a <= q) {
    data.seekp(a * sizeof(T));
    data >> aVal;
    tmp << aVal;
    ++a;
  }

  while (b <= r) {
    data.seekp(b * sizeof(T));
    data >> bVal;
    tmp << bVal;
    ++b;
  }

  data.seekg(p * sizeof(T));
  tmp.seekp(0);

  for (size_t i = p; i < r + 1; ++i) {
    tmp >> tmpVal;
    data << tmpVal;
  }
  tmp.sync();
  data.sync();
}